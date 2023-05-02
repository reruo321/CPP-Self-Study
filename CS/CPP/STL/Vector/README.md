# Vector
* Not good choice to insert/delete elements in the middle of the vector
## Releasing Memory of Vector

    // (v: vector)
    v.clear();          // Removes all elements from the vector, makes its size == 0.
    v.shrink_to_fit();      // This makes the container to reduce its capacity to fit its size. (capacity = size)

## *push_back()* vs *emplace_back()*
Guide: (1) [push_back() vs emplace_back() in C++ STL Vectors](https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors/), (2) [emplace_back vs push_back](https://gumeo.github.io/post/emplace-back/)

***push_back()*** puts an 'object'; It needs to create a temporary object (rvalue) for inserting, if there is no object! Meanwhile, ***emplace_back()*** do not need to create the temporary one. Just put some arguments, then the function will create an object inside it.

*emplace_back()* seems to be faster than *push_back()*, but **BE CAREFUL!** There is a risk of unwanted implicit conversion while using *emplace_back()*, because of constructor forwarding.
So if you are not sure about the conversion, it is better to just use *push_back()* for safety, reliability, and maintainability. 

## Reallocation and *push_back()*
> Calling push_back will cause reallocation (when size()+1 > capacity()).

According to notes on [cppreference](https://en.cppreference.com/w/cpp/container/vector/push_back),
we should be careful while spamming `push_back()`s! This can make some problems, for instance, when you are handling iterators on the vector.

It's better to use `insert()` for range inserting.
Or try to use `reserve()` if you are willing to try multiple `push_back()`s!
