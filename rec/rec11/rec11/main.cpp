// Liheng Cao lc4241 OOP Sec D

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
/*
  functions for use with CS2124 rec11
  -jbs
*/

// Node to be used a part of linked list
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
	headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like. 
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}


//task 1
void splice(Node* &add_in, Node* &add_to){
    if (!add_in || !add_to){return;}
    Node* old_next = add_to->next;
    add_to->next = add_in;
    Node* find_end = add_in;
    while (find_end->next){
        find_end = find_end->next;
    }
    find_end->next = old_next;
}

//task 2
void display_list(Node* a_node){
    if (a_node){
        for (;a_node;a_node=a_node->next){
            cout << a_node->data << " ";
        }
        cout << endl;
    }
}

Node* isSublist(Node* looking_for, Node* looking_in){
    for (Node* i = looking_in; i; i=i->next){
        if (looking_for->data == i->data){
            Node* j = looking_for;
            Node* k = i;
            while (j&&k){
                if (j->data == k->data){
                    j=j->next;
                    k=k->next;
                    if (!j){return i;}
                }
                else{break;}
            }
        }
    }
    return nullptr;
}



//task 3
Node* sharedListBruteForce(Node* &l1, Node* &l2){
    for (Node* i = l1; i; i=i->next){
        for (Node* j = l2; j; j=j->next){
            if (i == j){
                return i;
            }
        }
    }
    return nullptr;
}

Node* sharedListUsingSet(Node* &l1, Node* &l2){
    unordered_set<Node*> set;
    for (Node* i = l1; i; i=i->next){
        set.insert(i);
    }
    for (Node* i = l2; i; i=i->next){
        if (set.find(i) != set.end()){
            return i;
        }
    }
    return nullptr;
}

Node* sharedList_constspace(Node* &l1, Node* &l2){
//    find lengths
    unsigned len1 = 0;
    for (Node* i = l1; i; i=i->next){
        ++len1;
    }
    unsigned len2 = 0;
    for (Node* i = l2; i; i=i->next){
        ++len2;
    }
//    get to same amount left
    Node* start1 = l1;
    Node* start2 = l2;
    if (len1 > len2){
        for (unsigned i = 0; i < len1-len2; ++i){
            start1 = start1->next;
        }
    }
    else{
        for (unsigned i = 0; i < len2-len1; ++i){
            start2 = start2->next;
        }
    }
//    find common
    while(start1 != start2 && start1){
        start1 = start1->next;
        start2 = start2->next;
    }
    return start1;
}

int main(){
//    Part one
    cout << "Part One:\n\n";
    Node* L1 = listBuild({5,7,9,1});
    Node* L2 = listBuild({6,3,2});
    cout << "L1: ";
    display_list(L1);
    cout << "L2: ";
    display_list(L2);
    Node* target = L1->next;
    cout << "Target: ";
    display_list(target);
    cout << "Splicing L2 at target in L1\n";
    splice(L2, target);
    cout << "L1: ";
    display_list(L1);
    cout << "L2: ";
    display_list(L2);

//    Part two
    cout << "\n==============================\n\n";
    cout << "Target: ";
    listClear(target);
    target = listBuild({1,2,3,2,3,2,4,5,6});
    display_list(target);
    cout << endl;
    vector<vector<int>> lists = {
        {1},
        {3,9},
        {2,3},
        {2,4,5,6},
        {2,3,2,4},
        {5,6,7},
        {6}
    };
    for (size_t i = 0; i < lists.size(); ++i){
        cout << "Attempt match: ";
        Node* attempt = listBuild(lists[i]);
        display_list(attempt);
        Node* result = isSublist(attempt, target);
        if (result){
            display_list(result);
        }
        else{
            cout << "Failed to match\n";
        }
        cout << endl;
        listClear(attempt);
    }
    
//    Part three
    cout << "==============================\n\n";
    Node* l1 = listBuild({2,3,4,5});
    Node* l2 = l1->next->next;
    listAddHead(l2, 3);
    listAddHead(l2, 3);
    listAddHead(l2, 2);
    
    display_list(l1);
    display_list(l2);
    
    cout << "brute: " << sharedListBruteForce(l1, l2)->data << endl;
    cout << "set: " << sharedListUsingSet(l1, l2)->data << endl;
    cout << "const: " << sharedList_constspace(l1, l2)->data << endl;
}
