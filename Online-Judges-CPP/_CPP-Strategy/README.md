# C++ Strategy
The document is a C++ quick guide especially for online judges.
## Time Complexity

## Sort
### Header
    #include <algorithm>
### *sort()*
    template <class RandomAccessIterator>  void sort (RandomAccessIterator first, RandomAccessIterator last);
    template <class RandomAccessIterator, class Compare>  void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);

#### Example

    // ASC: Ascending order, DESC: Descending order

    // Helps sort() to sort elements in ASC.
    bool compare(const int &a, const int &b){
        return a < b;
    }
    
    .
    .
    .
    
    vector<int> vec1 = {5, 9, 3, 4, 7, 1, 2, 0, 8, 6};
    vector<vector<int>> vec_sort(5, vector<int>(vec1));


    sort(vec_sort.at(0).begin(), vec_sort.at(0).begin()+5);  // Sort up to fifth element (ASC)
    sort(vec_sort.at(1).begin(), vec_sort.at(1).end());     // Sort (ASC)
    sort(vec_sort.at(2).begin(), vec_sort.at(2).end(), compare);    // Sort (compare, ASC)
    sort(vec_sort.at(3).begin(), vec_sort.at(3).end(), less<int>());    // Sort (ASC)
    sort(vec_sort.at(4).begin(), vec_sort.at(4).end(), greater<int>());     // Sort (DESC)

    /*
        Original Vector: 5 9 3 4 7 1 2 0 8 6
        Sorted Vector 1: 3 4 5 7 9 1 2 0 8 6
        Sorted Vector 2: 0 1 2 3 4 5 6 7 8 9
        Sorted Vector 3: 0 1 2 3 4 5 6 7 8 9
        Sorted Vector 4: 0 1 2 3 4 5 6 7 8 9
        Sorted Vector 5: 9 8 7 6 5 4 3 2 1 0
    */

## String
### Header
    #include <string>
### *append()*
    string& append (const string& str);
    string& append (const string& str, size_t subpos, size_t sublen = npos);

#### Example

    string str1 = "Wow! ";
    string str3 = "Good ";
    string str5 = "What the ";
    string str2 = "Hello World";
    
    str1.append(str2);  // str1 == "Wow! Hello World"
    str3.append(str2, 6);  // str3 == "Good World"
    str5.append(str2, 0, 4);  // str5 == "What the Hell"

## Print
### *printf()*
    printf("%02x", buf);    // Prints the integer at least 2 digits in hexadecimal format, pad with 0s on the left it there's less than 2.
    printf("0.2f", abc);   // Prints the float, and output should have only 2 digits after the decimal place.

## Vector
### Release Memory of Vector

    // (v: vector)
    v.clear();          // Removes all elements from the vector, makes its size == 0.
    v.shrink_to_fit();      // This makes the container to reduce its capacity to fit its size. (capacity = size)

### *push_back()* vs *emplace_back()*
Guide: (1) [push_back() vs emplace_back() in C++ STL Vectors](https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors/), (2) [emplace_back vs push_back](https://gumeo.github.io/post/emplace-back/)

***push_back()*** puts an 'object'; It needs to create a temporary object (rvalue) for inserting, if there is no object! Meanwhile, ***emplace_back()*** do not need to create the temporary one. Just put some arguments, then the function will create an object inside it.

*emplace_back()* seems to be faster than *push_back()*, but **BE CAREFUL!** There is a risk of unwanted implicit conversion while using *emplace_back()*, because of constructor forwarding.
So if you are not sure about the conversion, it is better to just use *push_back()* for safety, reliability, and maintainability. 

## Queue

## Priority Queue
### Header
    #include <queue>
### Assignment
    // default comparison function is less(). Top element is the greatest.
    priority_queue<int> qu1;
    // greater() will make its top the least.
    priority_queue<int, vector<int>, greater<int>> qu2;

## Set
**Set**: Usually implemented red-black tree, only key
### Header
    #include <set>
### Assignment
    // Converting vector (vec) into set (s1)
    set<int> s1(vec.begin(), vec.end());
### *insert()*
    s1.insert(123);
### *find()*
Use iterator to search the container for an element.
(If no element, it returns set::end().)

    set<int> s1;
    set<int>::iterator it;
    .
    .
    .
    it=s1.find(321);

### *count()*

## Map
**Map**: Similar to set, key-value pairs, unique keys
### Header
    #include <map>
### Assignment
    map<string, int> m1;
### *insert()*
    m1.insert(make_pair("Hello", 123));
