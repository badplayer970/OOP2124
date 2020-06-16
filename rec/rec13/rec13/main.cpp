// rec13_test.cpp


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

//task 9
void p_list_iterator(const list<int> &the_list){
    list<int>::const_iterator iter = the_list.begin();
    while (iter != the_list.end()){
        cout << *iter << " ";
        ++iter;
    }
}

//task 10
void p_list_ranged(const list<int> &the_list){
    for (int i: the_list){
        cout << i << " ";
    }
}

//task 11
void  p_everyother_auto(const list<int> &the_list){
    for (auto i = the_list.begin(); i != the_list.end(); ++++i){
        cout << *i << " ";
    }
}

//task 12
//list<int>::const_iterator list_search(const list<int> &the_list, int target){
//    list<int>::const_iterator iter = the_list.begin();
//    while (iter != the_list.end()){
//        if (*iter == target) return iter;
//        ++iter;
//    }
//    return the_list.end();
//}

list<int>::const_iterator list_search(const list<int> &the_list, int target){
    for (list<int>::const_iterator iter = the_list.begin();
         iter != the_list.end();
         ++iter){
        if (*iter == target) return iter;
    }
    return the_list.end();
}

//task 13
//auto list_search(const list<int> &the_list, int target){
//    for (auto iter = the_list.begin();
//         iter != the_list.end();
//         ++iter){
//        if (*iter == target) return iter;
//    }
//    return the_list.end();
//}

//task 15
bool is_even(int n){return n % 2 == 0;}

//task 16
class divis{
public:
    bool operator()(int n)const {return n % 2 == 0;}
};

//task 19
auto ourFind(const list<int>::const_iterator &b,
             const list<int>::const_iterator &e, int target){
    cout << "running ourFind\n";
    for(auto i = b; i != e; ++i){
        if (*i == target) return i;
    }
    return e;
}

//task 20
template <typename T, typename U>
/*ourFindT(const typename list<T>::const_iterator &b,
                            const typename list<T>::const_iterator &e,
                            T target){*/
T ourFindT(T b, T e, U target){
    cout << "running template ourFind\n";
    for(T i = b; i != e; ++i){
        if (*i == target) return i;
    }
    return e;
}



//main
int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vec{2,4,6,1,3,0,5,9,8,7};
    for (int i: vec){
        cout << i << " ";
    }
    cout << "\n=======\n";
    
    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> lst(vec.begin(), vec.end());
    for (int i: lst){
        cout << i << " ";
    }
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vec.begin(), vec.end());
    for (int i: vec){
        cout << i << " ";
    }
    cout << "\n=======\n";
    
    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i = 0; i < vec.size(); i += 2){
        cout << vec[i] << " ";
    }
    cout << "\n=======\n";
    
    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
//    for (size_t i = 0; i < lst.size(); i += 2){
//        cout << lst[i] << " ";
//    }
    cout << "Does not compile";
    cout << "\n=======\n";
    
    //
    // Iterators
    //
    
    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter+= 2){
        cout << *iter << " ";
    }
    cout << "\n=======\n";
    
    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator iter = lst.begin(); iter != lst.end();
            ++++iter){
        cout << *iter << " ";
    }
    cout << "\n=======\n";
    
    // 8. Sorting a list
    cout << "Task 8:\n";
    lst.sort();
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter+= 1){
        cout << *iter << " ";
    }
    cout << "\n=======\n";
    
    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    p_list_iterator(lst);
    cout << "\n=======\n";
    
    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    p_list_ranged(lst);
    cout << "\n=======\n";
    
    //
    // Auto
    //
    
    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    p_everyother_auto(lst);
    cout << "\n=======\n";
    
    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    if (list_search(lst, 1) != lst.end()){
        cout << *list_search(lst, 1) << endl;
    }
    else{ cout << "1 not found" << endl;}
    if (list_search(lst, 12) != lst.end()){
        cout << *list_search(lst, 12) << endl;
    }
    else{ cout << "12 not found" << endl;}
//    cout << *list_search(lst, 1) << endl;
//    cout << *list_search(lst, 12);
    cout << "\n=======\n";
    
    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    if (list_search(lst, 1) != lst.end()){
        cout << *list_search(lst, 1) << endl;
    }
    else{ cout << "1 not found" << endl;}
    if (list_search(lst, 12) != lst.end()){
        cout << *list_search(lst, 12) << endl;
    }
    else{ cout << "12 not found" << endl;}
//    cout << *list_search(lst, 1) << endl;
//    cout << *list_search(lst, 12);
    cout << "\n=======\n";
    
    //
    // Generic Algorithms
    //
    
    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    if (find(lst.begin(), lst.end(), 1) != lst.end()){
        cout << *find(lst.begin(), lst.end(), 1) << endl;
    }
    else{ cout << "1 not found" << endl;}
    if (find(lst.begin(), lst.end(), 12) != lst.end()){
        cout << *find(lst.begin(), lst.end(), 1) << endl;
    }
    else{ cout << "12 not found";}
//    cout << *find(lst.begin(), lst.end(), 1) << endl;
//    cout << *find(lst.begin(), lst.end(), 12);
    cout << "\n=======\n";
    
    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    if (find_if(lst.begin(), lst.end(), is_even) != lst.end()){
        cout << *find_if(lst.begin(), lst.end(), is_even) << endl;
    }
    else{ cout << "even not found" << endl;}
//    cout << *find_if(lst.begin(), lst.end(), is_even);
    cout << "\n=======\n";
    
    // 16. Functor
    cout << "Task 16:\n";
    if (find_if(lst.begin(), lst.end(), divis()) != lst.end()){
        cout << *find_if(lst.begin(), lst.end(), divis()) << endl;
    }
    else{ cout << "even not found" << endl;}
//    cout << *find_if(lst.begin(), lst.end(), divis());
    cout << "\n=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    if (find_if(lst.begin(), lst.end(), [] (int n) {return n % 2 == 0;})
            != lst.end()){
        cout <<
        *find_if(lst.begin(), lst.end(), [] (int n) {return n % 2 == 0;})
        << endl;
    }
    else{ cout << "even not found" << endl;}
//    cout << *find_if(lst.begin(), lst.end(), [] (int n) {return n % 2 == 0;});
    cout << "\n=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* dynamic_array = new int[vec.size()];
    copy(vec.begin(), vec.end(), dynamic_array);
    for (int* i = dynamic_array; i != dynamic_array+vec.size(); ++i){
        cout << *i << " ";
    }
    delete [] dynamic_array;
    cout << "\n=======\n";
    
    //
    // Templated Functions
    //
    
    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    cout << *ourFind(lst.begin(), lst.end(), 1) << endl;
    cout << *ourFind(lst.begin(), lst.end(), 12);
    cout << "\n=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    cout << *ourFindT(lst.begin(), lst.end(), 1) << endl;
    cout << *ourFindT(lst.begin(), lst.end(), 12);
    cout << "\n=======\n";
    
    //
    // Associative collections
    //
    
    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    ifstream file("pooh-nopunc.txt");
    if (!file) exit(1);
    vector<string> words_in_file;
    string reader;
    while (file){
        file >> reader;
        if (find(words_in_file.begin(), words_in_file.end(), reader) ==
            words_in_file.end()){
            words_in_file.emplace_back(reader);
        }
    }
    file.close();
    cout << "size: " << words_in_file.size()<< endl;
    for (size_t i = 0; i < words_in_file.size(); ++i){
        cout << words_in_file[i] << " ";
    }
    cout << "\n=======\n";
    
    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    file.open("pooh-nopunc.txt");
    if (!file) exit(1);
    set<string> words_in_file_set;
    while (file){
        file >> reader;
        words_in_file_set.insert(reader);
    }
    file.close();
    cout << "size: " << words_in_file_set.size()<< endl;
    for (const string &s: words_in_file_set){
        cout << s << " ";
    }
    cout << "\n=======\n";
    
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    file.open("pooh-nopunc.txt");
    if (!file) exit(1);
    map<string, vector<int>> word_map;
    int location = 0;
    while (file){
        file >> reader;
        word_map[reader].push_back(location);
        ++location;
    }
    file.close();
    cout << "size: " << word_map.size()<< endl;
    for (const auto &p: word_map){
        cout << p.first << endl;
        for (int i: p.second){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "\n=======\n";
}
