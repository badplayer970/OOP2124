// Liheng Cao lc4241

#ifndef polynomial_hpp
#define polynomial_hpp

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>


namespace Math{

    class Polynomial{
        friend std::ostream& operator<<(
            std::ostream& os, const Polynomial &rhs);
    public:
        Polynomial();
        
        Polynomial(const std::vector<int> &v);
        
        Polynomial& operator+=(const Polynomial& rhs);
        
        Polynomial operator+(const Polynomial& rhs) const;
        
        bool operator==(const Polynomial& rhs) const;
        
        bool operator!=(const Polynomial& rhs) const;
        
        int evaluate(int x) const;
        
        Polynomial(const Polynomial& rhs);
        
        Polynomial& operator=(const Polynomial& rhs);
        
        ~Polynomial();
        
        void trim();
    private:
        struct Node{
            Node(int d=0, Node* n = nullptr);
            int data;
            Node* next;
        };
        Node* first = nullptr;
        unsigned long degree = 0;
        
        void listAddHead(Node*& headPtr, int data);
        
        Node* findTail(Node* headPtr);
        
        void deleteTail(Node* headPtr);
        
        void listAddTail(Node* headPtr, int data);
    };
}

#endif /* polynomial_hpp */
