# C++ Strategy
## Release Memory of Vector

    // (v: vector)
    v.clear();
    v.shrink_to_fit();

## *push_back()* vs *emplace_back()*
Guide: (1) [push_back() vs emplace_back() in C++ STL Vectors](https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors/), (2) [emplace_back vs push_back](https://gumeo.github.io/post/emplace-back/)

***push_back()*** puts an 'object'; It needs to create a temporary object (rvalue) for inserting, if there is no object! Meanwhile, ***emplace_back()*** do not need to create the temporary one. Just put some arguments, then the function will create an object inside it.

*emplace_back()* seems to be faster than *push_back()*, but **BE CAREFUL!** There is a risk of unwanted implicit conversion while using *emplace_back()*.
So if you are not sure about the conversion during constructor forwarding, it is better to just use *push_back()* for safety, reliability, and maintainability. 
