# C++ Strategy
The document is a C++ quick guide especially for online judges.
## Avoiding Time Limit Exceeded Problem
1. Analyze time constraints. 1-sec time limit will allow your process to run **10^8** operaions.
2. Use faster I/O method. Use *printf()*/*scanf()* instead of *cin()*/*cout()*.
3. No 4 or more nested loops if N >= 100.
4. Try to reduce loops in your program.

## Time Complexity
Guide: [Guide 1](https://adrianmejia.com/how-to-find-time-complexity-of-an-algorithm-code-big-o-notation/)
, [Guide 2](https://adrianmejia.com/most-popular-algorithms-time-complexity-every-programmer-should-know-free-online-tutorial-course/#Mergesort)

![Complexities-Graph1](https://user-images.githubusercontent.com/48712088/222981233-a6b1c11a-8c49-4162-94ae-69380c8d3a08.png)

We can find time complexity of codes by counting performed opperations, by using **Big-O notation**.

* ***n***: input size
* ***O***: The worst-case scenario growth rate function

A simple, intuitive way to know the complexity of a function is just putting n=1, n=2, n=3, ... and so on.

### Examples
* **O(1)**(Constant): Primitive operations (+-×/%, bit shift, etc.), Average lookup/inserting/deleting in hash table (Worst is O(n).)
* **O(logn)**(Logarithmic): Binary search
* **O(n)**(Linear): Single loop
* **O(nlogn)**(Linearithmic): Merge sort, Quick sort, ...
* **O(n^2)**(Quadratic): Double loop, Bubble sort
* **O(n^c)**(Polynomial): c-loop
* **O(2^n)**(Exponential): Power set (finding all subsets on a set), Fibonacci
* **O(n!)**(Factorial): Permutation

### Notes
* The absolute value of a number does not matter in primitive operations. (Both "4+3" and "53837493+2838384" are O(1).)
* Since primitive operations have maximum-value limits, they can have constant time.
* One-line code ≠ O(1)
* Use only dominant term in O notation, without coefficients. if f(n) = 3n^2+2n+1, O(g(n)) = O(n^2).

#### Master Theorem
[**Master theorem**](https://en.m.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms)): Asymptotic analysis for recurrence relations of types. **T(n) = aT(n/b) + f(n)**
where *a*: No. of subproblems, *b*: the factor by which *n* is reduced, *f(n)*: the running time outside of the recursion.

The recurrences often satisfy one of three forms, which is determined by how the work to split/recombine the problem *f(n)* relates to the critical exponent ccrit. = logb(a).

For example, master theorem can be used to find the running time of binary search or merge sort.

## Sort
### Header
    #include <algorithm>
### *sort()*
    template <class RandomAccessIterator> void sort (RandomAccessIterator first, RandomAccessIterator last);
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
### Operators
There are various operators supported on string.

***operator=*** (assignment), ***operator[]*** (get character), ***operator+=*** (appending),
***operator+*** (concatenation), ***operator>>*** (istream), ***operator<<*** (ostream).

***Relational operators*** (such as operator==, operator<=) can be also used.
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

### *substr()*
    string substr (size_t pos = 0, size_t len = npos) const;
#### Example
    string str1 = "Hello World!";
    string str2 = str1.substr(0, 4);    // str2 == "Hell"
### *push_back()*
    str.push_back('X');
    str.push_back('5');
### *pop_back()*
    str.pop_back();
### *size()*
***size()* = *length()*** in string.
### *compare()*
    if(str1.compare(str2) == 0)
        cout << "They are the same." << endl;
    if(str1.compare(str3) != 0)
        cout << "They are different." << endl;
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

## Stack
**Stack**: LIFO
## Queue
**Queue**: FIFO

## Priority Queue

### Header
    #include <queue>
### Assignment
    // default comparison function is less(). Top element is the greatest.
    priority_queue<int> qu1;
    // greater() will make its top the least.
    priority_queue<int, vector<int>, greater<int>> qu2;

## Deque
**Deque**: The double-ended queue
### *push_front()*
### *push_back()*
### *pop_front()*
### *pop_back()* 
### *at()*
Note that you can use *at()* on a deque, which is unavailable on a queue.

    de.at(1);
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
    if(s1.count(222) > 0)
      cout << "There is 222 in the set." << endl;

## Map
* Associative container: Element reference - Key (O) Absolute position (X)
* Ordered: Strict elements' order at all times
* Map: Key - Mapped value
* Unique keys: No equivalent keys
* Allocator-aware: Allovator object for dynamically handling storage needs

### Header
    #include <map>
### Assignment
    map<string, int> m1;
### *insert()*
    m1.insert(make_pair("Hello", 123));
### *count()*
Since normal maps have unique keys, map::count will return either 0 or 1.

    if(m1.count("Oh") > 0)
      cout << "You said OH." << endl;

## List
**List**: Sufficient for inserting/deleting elements, even if they are not on the edge.
(Some other containers such as vector would not be good choices for that.)

### **erase()**

## Forward List
