//
//  main.cpp
//  rec14
//
//  Created by liheng cao on 5/8/20.
//  Copyright © 2020 liheng cao. All rights reserved.
//

#include <iostream>
#include <stdexcept>

using namespace std;

// even bits
bool even1s(int n){
    if (n == 0) return true;
    if (n == 1) return false;
    if (n % 2 == 0) return even1s(n/2);
    return !even1s(n/2);
}

// list
struct Node{
    int data = 0;
    Node* next = nullptr;
};


void display_list(Node* a_node){
    if (a_node){
        for (;a_node;a_node=a_node->next){
            cout << a_node->data << " ";
        }
        cout << endl;
    }
}

Node* sumLists(Node* l1, Node* l2){
    if (l1 && l2){
        Node* next = sumLists(l1->next, l2->next);
        return new Node{l1->data+l2->data, next};
    }
    if (l2){
        Node* next = sumLists(nullptr, l2->next);
        return new Node{l2->data, next};
    }
    if (l1){
        Node* next = sumLists(nullptr, l1->next);
        return new Node{l1->data, next};
    }
    return nullptr;
}

// tree
struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

int max_t(TNode* root) {
    if (root){
        if (root->left && root->right){
            return max(root->data,
                       max(max_t(root->left),
                           max_t(root->right)));
        }
        if (root->left){
            return max(root->data,
                       max_t(root->left));
        }
        if (root->right){
            return max(root->data,
                       max_t(root->right));
        }
        return root->data;
    }
    throw invalid_argument("no max for empty tree");
}

// palindrome
bool palindrome(char* s, size_t l){
    if (l < 2) return true;
    return s[0] == s[l-1] && palindrome(&s[1], l-2);
}

// tower of hanoi
int tower_moves(int disks){
    if (disks < 1) throw invalid_argument("invalid argument");
    if (disks == 1) return 1;
    return 2 * tower_moves(disks-1) + 1;
}

// mystery

//
//1 c
//2 acbcc
//3 acbcc
//4 aacbccbacbccc
//5 aacbccbacbccc
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}

int main() {
//    even bits
    cout << boolalpha;
    for (int i = 0; i < 8; ++i){
        cout << i << ": " << even1s(i) << endl;
    }
// list
    Node* lst1 = new Node{0};
    Node* lst2 = new Node{1000};
    Node* cur = lst1;
    for (int i = 1; i < 5; ++i){
        cur->next = new Node{i};
        cur = cur->next;
    }
    cur = lst2;
    for (int i = 1100; i < 1700; i += 100){
        cur->next = new Node{i};
        cur = cur->next;
    }
    display_list(lst1);
    display_list(lst2);
    
    display_list(sumLists(lst1, lst2));
    
//    tree
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    
    cout << max_t(&f) << endl;
    try{
        cout << max_t(nullptr) << endl;
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
    }
    
    try{
        cout << max_t(&a) << endl;
    }
    catch(const invalid_argument& e){
        cout << e.what() << endl;
    }
    cout << "done\n";
    
//    palindrome
    char s1[] = "noon";
    char s2[] = "mom";
    char s3[] = "asdfavdjkn";
    cout << "noon: " << palindrome(s1, 4) << endl;
    cout << "mom: " << palindrome(s2, 3) << endl;
    cout << "asdfavdjkn: " << palindrome(s3, 10) << endl;
    
//    towers of hanoi
//    towers(1, 'a', 'b', 'c'): 1
//    towers(2, 'a', 'b', 'c'): 3
//    towers(3, 'a', 'b', 'c'): 7
//    towers(4, 'a', 'b', 'c'): 15
//    towers(5, 'a', 'b', 'c'): 31
//    towers(6, 'a', 'b', 'c'): 63
//    towers(7, 'a', 'b', 'c'): 127
//    towers(8, 'a', 'b', 'c'): 255
//    towers(9, 'a', 'b', 'c'): 511
//    towers(10, 'a', 'b', 'c'): 1023
    for (int i = 0; i < 10; ++i){
        cout << i << ": " << tower_moves(i+1) << endl;
    }
    
//    mystery code
//    if (n > 1) {
//        cout << 'a';
//        mystery(n/2);
//        cout << 'b';
//        mystery(n/2);
//    }
//    cout << 'c';
    
//    0: c
//    1: c
//    2: acbcc
//    3: acbcc
//    4: aacbccbacbccc
//    5: aacbccbacbccc
//    6: aacbccbacbccc
//    7: aacbccbacbccc
//    8: aaacbccbacbcccbaacbccbacbcccc
//    9: aaacbccbacbcccbaacbccbacbcccc
//    10: aaacbccbacbcccbaacbccbacbcccc
    
    for (int i = 0; i < 11; ++i){
        cout << i << ": ";
        mystery(i);
        cout << endl;
    }
    
}




