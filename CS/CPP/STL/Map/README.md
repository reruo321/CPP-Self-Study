# Map
* Associative container: Element reference - Key (O) Absolute position (X)
* Ordered: Strict elements' (keys') order at all times
* Map: Key - Mapped value
* Unique keys: No equivalent keys
* Allocator-aware: Allocator object for dynamically handling storage needs

## Header
    #include <map>
## Assignment
    map<string, int> m1;
## Comparison
### 1. Using Struct
    struct comp {
        bool operator()(const int& a, const int& b) const {
            return a > b;
        }
    };
    map<int, int, comp> ma;

### 2. (C++11) Using Lambda Expression
    auto comp = [](const int& a, const int& b) { return a > b; };
    map<int, int, decltype(comp)> ma(comp);

## *insert()*
    m1.insert(make_pair("Hello", 123));
## *find()*
    if(m1.find("Wow")==m1.end())
      cout << "You didn't say Wow." << endl;
## *count()*
Since normal maps have unique keys, map::count will return either 0 or 1.

    if(m1.count("Oh") > 0)
      cout << "You said Oh." << endl;

# Unordered Map
* Not ordered by keys or mapped values
* Organized into **buckets** with their hash value for faster accessing
## Map vs Unordered Map

| - | Map | Unordered Map |
| - | - | - |
| Ordering | Key ASC | X |
| Implementation | Self balancing BST | Hash Table |
| Search Time | log(n) | Average: O(1)<br>Worst: O(n) |
| Insertion Time | log(n) + Rebalance | " |
| Deletion Time | log(n) + Rebalance | " |
| General Usage | Range iteration | Accessing individuals |
