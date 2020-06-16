// Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
    friend ostream& operator<<(ostream& os, const List& li){
//        os << "list start:\n";
        if (li.size()){
            Node* cur = li.header->next;
            for (size_t i = 0; i < li.size(); ++i){
                os << cur->data << " ";
                cur = cur->next;
            }
//            os << "list end:\n";
        }
//        else{
//            os << "list is empty\n";
//        }
        
        return os;
    }
    
    struct Node{
        int data = -1;
        Node* prior = nullptr;
        Node* next = nullptr;
    };
    
    
    
public:
    class iterator{
    public:
        friend List;
        iterator(Node* n){
            node = n;
        }
        
        iterator operator++(){
            node = node -> next;
            return *this;
        }
        
        iterator operator--(){
            node = node->prior;
            return *this;
        }
        
        bool operator==(const iterator& rhs) const {
            return node == rhs.node;
        }
        
        bool operator!=(const iterator& rhs) const {
            return !(*this==rhs);
        }
        
        int operator*(){
            return node->data;
        }
    private:
        Node* node;
    };
    
    iterator begin(){
        return iterator(header->next);
    }
    
    iterator end(){
        return iterator(trailer);
    }
    
    List(){
        header->next = trailer;
        trailer->prior = header;
    }
    
    List(List& rhs): List(){
        for (int i: rhs){
            push_back(i);
        }
    }
    
    ~List(){
        clear();
        cout << "~list()\n";
    }
    
    List operator=(List& rhs){
        if (this != &rhs){
            clear();
            for (int i: rhs){
                push_back(i);
            }
        }
        return *this;
    }
    
    void push_back(int data){
        Node* n = new Node{data, trailer->prior, trailer};
        trailer->prior->next = n;
        trailer->prior = n;
        ++l_size;
    }
    
    void pop_back(){
        if (size()==0) return;
        Node* p = trailer->prior->prior;
        delete trailer->prior;
        trailer->prior = p;
        p->next = trailer;
        --l_size;
    }
    
    void push_front(int data){
        Node* n = new Node{data, header, header->next};
        header->next->prior = n;
        header->next = n;
        ++l_size;
    }
    
    void pop_front(){
        if (size()==0) return;
        Node* p = header->next->next;
        delete header->next;
        header->next = p;
        p->prior = header;
        --l_size;
    }
    
    int front() const {
        return header->next->data;
    }
    
    int back() const {
        return trailer->prior->data;
    }
    
    int& front() {
        return header->next->data;
    }
    
    int& back() {
        return trailer->prior->data;
    }
    
    unsigned size() const {
        return l_size;
    }
    
    void clear(){
        if (size()){
            Node* cur = header->next->next;
            for (size_t i = 0; i < size(); ++i){
                delete cur->prior;
                cur->prior = nullptr;
                cur = cur -> next;
            }
        }
        header->next = trailer;
        trailer->prior = header;
        l_size = 0;
    }
    
    int operator[](size_t k) const{
        Node* cur = header->next;
        for (size_t i = 0; i < k; ++i){
            cur = cur->next;
        }
        return cur->data;
    }
    
    int& operator[](size_t k){
        Node* cur = header->next;
        for (size_t i = 0; i < k; ++i){
            cur = cur->next;
        }
        return cur->data;
    }
    
    iterator insert(iterator iter, int num){
        Node* n = new Node{num, iter.node->prior, iter.node};
        iter.node->prior->next = n;
        iter.node->prior = n;
        ++l_size;
        return iterator(n);
    }
    
    iterator erase(iterator iter){
        iterator i = iterator(iter.node->next);
        iter.node->prior->next = iter.node->next;
        iter.node->next->prior = iter.node->prior;
        delete iter.node;
        iter.node = nullptr;
        --l_size;
        return i;
    }
private:
    Node* header = new Node{};
    Node* trailer = new Node{};
    unsigned l_size=0;
};




// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}
//
// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << "Leaving doNothing\n";
}

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);


    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
