//  lc4241
//  main.cpp
//  rec9

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned num):numberOfPages(num){}
    virtual void displayNumPages() const = 0;
protected:
private:
    unsigned numberOfPages;
};
void PrintedMaterial::displayNumPages() const {
    cout << "num pages" << numberOfPages << endl;
}


class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned num):PrintedMaterial(num){};
    void displayNumPages() const {
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned num):PrintedMaterial(num){};
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned num, unsigned numIndex):Book(num),
        numOfIndexPages(numIndex){};
    void displayNumPages() const {
        PrintedMaterial::displayNumPages();
        cout << "numIndex " << numOfIndexPages << endl;
    }
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned num):Book(num){};
    void displayNumPages() const {
        PrintedMaterial::displayNumPages();
    }
protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& pm){
    pm.displayNumPages();
}

// tester/modeler code
int main(){
    TextBook t(1,2);
    Novel n(2);
    Magazine m(3);
    
    
    cout << "t:";
    t.displayNumPages();
    
    cout << "n:";
    n.displayNumPages();
    
    cout << "m:";
    m.displayNumPages();
    
    
//    PrintedMaterial pm(3);
//    cout << "pm:";
//    pm.displayNumPages();
    
//    PrintedMaterial* PMPtr;
//    PMPtr = &n;
//    cout << "pointer n:";
//    PMPtr->displayNumPages();
//
//    PMPtr = &t;
//    cout << "pointer t:";
//    PMPtr->displayNumPages();
//
//    cout << "new pm:";
//    pm = t;
//    pm.displayNumPages();
    
//    cout << "method t:";
//    displayNumberOfPages(t);
    
    vector<PrintedMaterial*> vec;
    
    vec.push_back(&t);
    vec.push_back(&n);
    vec.push_back(&m);
//    vec.push_back(PMPtr);
    
    for (size_t i = 0; i < vec.size(); ++i){
        vec[i]->displayNumPages();
        cout << endl;
    }
}
