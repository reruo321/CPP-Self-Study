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

### Auxiliary Space and Space Complexity
* **Auxiliary Space**: The extra space or temporary spave used by an algorithm
* **Space Complexity**: Auxiliary space + Space used by input

## Behavior
### Summary
| | **Well-defined** | **Implementation**<br>**-defined** | **Unspecified** | **Undefined** |
| :-: | :-: | :-: | :-: | :-: |
| Compiler must do something | O | O | O | X |
| Compiler must document it | O | O | X | X |
| Improves the portability? | O | X | X | X |

### Well-defined Behavior
**Well-defined behavior** is the behavior strictly conforming to the C++ standard. It is neither IB, UsB, nor UB.
It is ideally portable without change, and has the strongest guarantees to their users.

### Implementation-defined Behavior
**Implementation-defined behavior(IB)** is the behavior that must be documented by the *particular* compiler/platform, according to the standard, and it must do something precisely.

#### Examples
* The mapping result of `reinterpret_cast`. It usually does not modify the address. However, since the "mapping" is an IB, a compiler can make it different if the compiler documented it.
* The size of integral types in bytes. The C++ standard does not specify it, and it does not matter if it is 2, 4, or 8. Nevertheless, a compiler must document it.
* The `>>` operator on a negative number.

### Unspecified Behavior
**Unspecified behavior(UsB)** is the behavior a compiler must do something on it, similar to IB. It does not have to be documented by it, though.

### Undefined Behavior
**Undefined behavior(UB)** is the thing a compiler can do whatever on, including crashing or giving unpredictable results.

"Why the standard does not mandate implementations to handle these annoying UBs?": Not checking possibility of UBs brings quite a lot of optimization, and extensibility on C++.

#### Example
* Dereferencing the null pointer.
* The pointer arithmetic resulting in the out-of-bounds of an array.

# C++ STL
## Sort
### Header
    #include <algorithm>
### *sort()*
    template <class RandomAccessIterator> void sort (RandomAccessIterator first, RandomAccessIterator last);
    template <class RandomAccessIterator, class Compare> void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);

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

### *find()*
Very useful to parse or find something in the string.
#### Example
    size_t found = str.find("#");
    string my_string = str.substr(0, found);
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

### *npos*
    static const size_t npos = -1;

`npos` is a static member constant value with the maximum value for the type `size_t`.

#### Usage
1. As a value for ***len/sublen*** parameter: **Until the end of the string**.
2. As a return value: Usually "No matches".

### Notes
**BE CAREFUL** while dealing with chars and strings together!

Suppose that you want to make a string `hi AB`,
by concatenating some chars and a string.
    
    char a = 'A';
    char b = 'B';
    string str = "hi ";
    
    str += a + b;   // OH NO!
    
    cout << str << endl;

However, the result is `hi �`.
The precedence of the operator `+` is higher than that of `+=`.
Therefore, `a+b` is done first.

    str += to_string(a) + to_string(b);   // No.

The second try is not good neither, since its output is `hi 6566`.

    str = str + a + b;   // Right!

This is one of the right answer. As the associativity of `+` is left-to-right,
it will add chars to the string in sequence.

Also, pay attention to **parameters** for some member functions,
if there is a char! They need `n` before a char argument,
which means the number of the characters.

    // The functions which use "n" as a parameter.
    str.append(n, '*');
    str.assign(n, '*');
    str.insert(0, n, '*');
    str.replace(0, 1, n, '*');

The other functions such as *string::push_back()* do not need to put the number.

## Print
### *printf()*
    printf("%02x", buf);    // Prints the integer at least 2 digits in hexadecimal format, pad with 0s on the left it there's less than 2.
    printf("0.2f", abc);   // Prints the float, and output should have only 2 digits after the decimal place.

## Vector
* Not good choice to insert/delete elements in the middle of the vector
### Releasing Memory of Vector

    // (v: vector)
    v.clear();          // Removes all elements from the vector, makes its size == 0.
    v.shrink_to_fit();      // This makes the container to reduce its capacity to fit its size. (capacity = size)

### *push_back()* vs *emplace_back()*
Guide: (1) [push_back() vs emplace_back() in C++ STL Vectors](https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors/), (2) [emplace_back vs push_back](https://gumeo.github.io/post/emplace-back/)

***push_back()*** puts an 'object'; It needs to create a temporary object (rvalue) for inserting, if there is no object! Meanwhile, ***emplace_back()*** do not need to create the temporary one. Just put some arguments, then the function will create an object inside it.

*emplace_back()* seems to be faster than *push_back()*, but **BE CAREFUL!** There is a risk of unwanted implicit conversion while using *emplace_back()*, because of constructor forwarding.
So if you are not sure about the conversion, it is better to just use *push_back()* for safety, reliability, and maintainability. 

### Reallocation and *push_back()*
> Calling push_back will cause reallocation (when size()+1 > capacity()).

According to notes on [cppreference](https://en.cppreference.com/w/cpp/container/vector/push_back),
we should be careful while spamming `push_back()`s! This can make some problems, for instance, when you are handling iterators on the vector.

It's better to use `insert()` for range inserting.
Or try to use `reserve()` if you are willing to try multiple `push_back()`s!

## Stack
**Stack**: LIFO
## Queue
**Queue**: FIFO

## Priority Queue
**Priority queue** automatically sorts the elements in the queue.
### Header
    #include <queue>
### Assignment
    // default comparison function is `less()`. **Top element is the greatest.**
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
**Set**: Usually implemented red-black tree, has only keys
### Header
    #include <set>
### Assignment
    // Lambda expression to set order of container
    auto comp = [](const int &a, const int &b){
        return a > b;
    };
    .
    .
    .
    set<int, decltype(comp)> se(comp);

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
The return value will be always `0` OR `1`, since normal `set` does not allow duplicated keys.

    if(s1.count(222) > 0)
      cout << "There is 222 in the set." << endl;

### *lower_bound()* & *upper_bound()*
    auto comp = [](const int &a, const int &b){
        return a > b;
    };

    .
    .
    .

    set<int, decltype(comp)> se(comp);
    for(int i=1; i<10; ++i)
        se.insert(i);
    
    for(auto &s: se) cout << s << " ";
    cout << endl;

    // 9 8 7 6 5 4 3 2 1
    
    set<int>::iterator itd, itu;
    itd = se.lower_bound(6);
    itu = se.upper_bound(2);
    se.erase(itd, itu);
    
    for(auto &s: se) cout << s << " ";
    cout << endl;

    // 9 8 7 1

## Map
* Associative container: Element reference - Key (O) Absolute position (X)
* Ordered: Strict elements' (keys') order at all times
* Map: Key - Mapped value
* Unique keys: No equivalent keys
* Allocator-aware: Allocator object for dynamically handling storage needs

### Header
    #include <map>
### Assignment
    map<string, int> m1;
### Comparison
#### 1. Using Struct
    struct comp {
        bool operator()(const int& a, const int& b) const {
            return a > b;
        }
    };
    map<int, int, comp> ma;

#### 2. (C++11) Using Lambda Expression
    auto comp = [](const int& a, const int& b) { return a > b; };
    map<int, int, decltype(comp)> ma(comp);

### *insert()*
    m1.insert(make_pair("Hello", 123));
### *find()*
    if(m1.find("Wow*)==m1.end())
      cout << "You didn't say Wow." << endl;
### *count()*
Since normal maps have unique keys, map::count will return either 0 or 1.

    if(m1.count("Oh") > 0)
      cout << "You said Oh." << endl;

## Unordered Map
* Not ordered by keys or mapped values
* Organized into **buckets** with their hash value for faster accessing
### Map vs Unordered Map

| - | Map | Unordered Map |
| - | - | - |
| Ordering | Key ASC | X |
| Implementation | Self balancing BST | Hash Table |
| Search Time | log(n) | Average: O(1)<br>Worst: O(n) |
| Insertion Time | log(n) + Rebalance | " |
| Deletion Time | log(n) + Rebalance | " |
| General Usage | Range iteration | Accessing individuals |

## List
**List**: Sufficient for inserting/deleting elements, even if they are not on the edge.
(Some other containers such as vector would not be good choices to do them.)

### Iterator
Make its iterator to find, erase, or go to a loop.

    list<int> mylist;
    list<int>::iterator it;

### **erase()**
**WARNING!** You should assign the iterator again when you are erasing something, or it will point to erased element.
(Do not need to take care of it while using vector though.)

    it = mylist.erase(it);  // Should do like this!
    mylist.erase(it);   // In this line "it" will point to ERASED element...

## Forward List

# Others
## Rope
* Scalable string
* String operations (concatenate, substr, ...) are almost independent of the length of the string
* Member functions are similar to those of `string`.

NOTE: It is not from the C++ standard library. From SGI extensions.

### Header
    #include <ext/rope>
### Namespace
    using namespace __gnu_cxx;
### Convert String to Rope
You can choose c-string (via string::c_str) as a vehicle.

    string str;
    crope ro(str.c_str());
### *insert()*
### *append()*
### *erase()*

