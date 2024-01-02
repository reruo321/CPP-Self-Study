# Input and Output in C++

## `cin`

### `cin.ignore()`

    #include <iostream>
    using namespace std;

    string str;
    cin.ignore(N, C) >> str;

Ignores up to `N` characters or until it encounters the specified delimiter character `C`. If `C` is not specified (the default is `EOF`), it will ignores the first `N` characters.

When using `std::cin` and then `std::getline()`, 

#### Example 1
* N=3
* C is not specified
* Input: "abcdefgh"

> str: defgh
#### Example 2
* N=3
* C='e'
* Input: "abcdefgh"

> str: defgh

#### Example 3
* N=7
* C is not specified
* Input: "abcdefgh"

> str: h
#### Example 4
* N=7
* C='e'
* Input: "abcdefgh"

> str: fgh

#### Example 5
* N=20
* C is not specified
* input:

  "abcde

  fghij

  klmno

  pqrst"

> str: rst

#### Example 6
* N=20
* C='h'
* input:

  "abcde

  fghij"

> str: ij

## `cout`
