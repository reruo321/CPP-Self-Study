# Rope
* Scalable string
* String operations (concatenate, substr, ...) are almost independent of the length of the string
* Member functions are similar to those of `string`.

NOTE: While it is a part of the C++ STL, it is not in the C++ standard library. You can find it from SGI extensions.

## Header
    #include <ext/rope>
## Namespace
    using namespace __gnu_cxx;
## Convert String to Rope
You can choose c-string (via string::c_str) as a vehicle.

    string str;
    crope ro(str.c_str());

After making a `rope`, you can use it as if it were a `string`.

