# extern
The keyword `extern` specifies that the symbol (global variable, function, or template declaration) has an external linkage.

## extern "C"
To use symbols from C++ source to C, we should use `extern "C"`.
It notifies a C++ compiler "not to do" **name mangling** on the C++ symbols.

### Name Mangling
**Name mangling** is one of the C++ features to support **function overloading**.
To distinguish between different functions with the same name when generating object code, the C++ compilers change some symbols' name and encode their information.
Different compilers may have different naming rules.

Name mangling enables to avoid duplicated-symbols'-name conflicts in binary code while compiling C++ source code.
However, since C does not support function overloading, it may make some problems when you try to link C and C++ source codes.
In that case, use `extern "C"` block to ensure that the symbols' names inside it are not changed.
