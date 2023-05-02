# Set
**Set**: Usually implemented red-black tree, has only keys
## Header
    #include <set>
## Assignment
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
## *insert()*
    s1.insert(123);
## *find()*
Use iterator to search the container for an element.
(If no element, it returns set::end().)

    set<int> s1;
    set<int>::iterator it;
    .
    .
    .
    it=s1.find(321);

## *count()*
The return value will be always `0` OR `1`, since normal `set` does not allow duplicated keys.

    if(s1.count(222) > 0)
      cout << "There is 222 in the set." << endl;

## *lower_bound()* & *upper_bound()*
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
