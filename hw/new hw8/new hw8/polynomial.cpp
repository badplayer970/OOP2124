// Liheng Cao lc4241

#include "polynomial.hpp"

namespace Math{
//    Node constructor
    Polynomial::Node::Node(int d, Polynomial::Node* n):data(d), next(n){}

// functions from lecture, etc.
    void Polynomial::listAddHead(Polynomial::Node*& headPtr, int data) {
        headPtr = new Polynomial::Node(data, headPtr);
    }

    Polynomial::Node* Polynomial::findTail(Polynomial::Node* headPtr) {
        if (headPtr == nullptr) return nullptr;
        Polynomial::Node* p = headPtr;
        while (p->next != nullptr) {
            p = p->next;
        }
        return p;
    }
    
    void Polynomial::deleteTail(Node* headPtr){
        if (headPtr == nullptr) return;
        Node* cur = headPtr;
        Node* prev = nullptr;
        while (cur->next != nullptr) {
            prev = cur;
            cur = cur->next;
        }
        delete cur;
        prev->next = nullptr;
    }

    void Polynomial::listAddTail(Polynomial::Node* headPtr, int data) {
        Polynomial::Node* tail = findTail(headPtr);
        tail->next = new Polynomial::Node(data);
    }


// Polynomial
    std::ostream& operator<<(std::ostream& os, const Polynomial &rhs){
        std::string output="";
        Polynomial::Node* cur = rhs.first;
        int p = 0; // exponent counter
        while (cur){ // run while there are Nodes to display
            if (p == 0){ // first, constant term, w/ power 0
                // only need coef
                output = std::to_string(cur->data);
            }
            else if (cur->data == 0){ // skip if coef is 0, unless first term
                ++p;
                cur = cur->next;
                continue;
            }
            else if (cur->data == 1){
//                if coef is 1, don't include it
                if (p == 1){ // second term, w/ power 1
                                  // only need coef and x, don't need pow
                    output = "x + "+ output;
                }
                else{
                    output = "x^" + std::to_string(p) + " + " + output;
                }
            }
            else if (p == 1){ // second term, w/ power 1
                // only need coef and x, don't need pow
                output = std::to_string(cur->data)+ "x + "+ output;
            }
            else{
                output = std::to_string(cur->data)
                + "x^" + std::to_string(p) + " + "
                + output;
            }
            ++p;
            cur = cur->next;
        }
        os << output;
        return os;
    }

    Polynomial::Polynomial():degree(0){
        first = new Node(0);
    };

    Polynomial::Polynomial(const std::vector<int> &v):degree(v.size()-1){
        for (int coef: v){
            first = new Node(coef, first);
        }
        trim(); // get rid of leading 0's
    }

    Polynomial& Polynomial::operator+=(const Polynomial& rhs){
        Node* cur = first;
        Node* rcur = rhs.first;
        while (cur && rcur){ // += data values when both have them
            cur->data += rcur->data;
            cur = cur->next;
            rcur = rcur->next;
        }
        while (rcur){ // add to tail if one runs out
            listAddTail(first, rcur->data);
            rcur = rcur->next;
        }
        if (degree < rhs.degree) degree = rhs.degree;
        trim();
        return *this;
    }

    Polynomial Polynomial::operator+(const Polynomial& rhs) const {
        Polynomial res(*this);
        res += rhs;
        res.trim();
        return res;
    }

    bool Polynomial::operator==(const Polynomial& rhs) const {
        if (degree != rhs.degree) return false;
        Node* cur = first;
        Node* rcur = rhs.first;
        while (cur && rcur){
            if (cur->data != rcur->data) return false;
            cur = cur->next;
            rcur = rcur->next;
        }
        return true;
    }

    bool Polynomial::operator!=(const Polynomial& rhs) const {
        return !(*this==rhs);
    }

    int Polynomial::evaluate(int x) const {
        int res = 0;
        int p = 1; // p keeps track of x^(...)
        Node* cur = first;
        while (cur){
            res += cur->data * p;
            cur = cur->next;
            p *= x;
        }
        return res;
    }

    Polynomial::Polynomial(const Polynomial& rhs){
        Node* rcur = rhs.first;
        while (rcur){
            if (!first){ // first run need to add a head
                listAddHead(first, rhs.first->data);
            }
            else{ // other runs add to tail
                listAddTail(first, rcur->data);
            }
            rcur = rcur->next;
        }
        degree = rhs.degree;
    }

    Polynomial& Polynomial::operator=(const Polynomial& rhs){
        if (*this != rhs){
            while (first){ // clear first
                Node* cur = first->next;
                delete first;
                first = cur;
            }
            Node* rcur = rhs.first;
            while (rcur){
                if (first){
                    listAddTail(first, rcur->data);
                }
                else{
                    listAddHead(first, rhs.first->data);
                }
                rcur = rcur->next;
            }
            degree = rhs.degree;
        }
        trim();
        return *this;
    }
    
    Polynomial::~Polynomial(){
        Node* cur = first;
        while(first){
            cur = cur->next;
            delete first;
            first = cur;
        }
    }
    
    void Polynomial::trim() { // get rid of leading 0's
        while (findTail(first)->data == 0){
            deleteTail(first);
            --degree;
        }
    }
    
}
