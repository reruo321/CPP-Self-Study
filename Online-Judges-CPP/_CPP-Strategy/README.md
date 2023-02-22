# C++ Strategy
## Time Complexity

## Print
### *printf*
    printf("%02x", buf);    // Prints the integer at least 2 digits in hexadecimal format, pad with 0s on the left it there's less than 2.
    printf("0.2f", );   // Prints the float, and output should have only 2 digits after the decimal place.

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
