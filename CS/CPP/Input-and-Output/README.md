# Input and Output in C++

## `cin`
`cin` leaves a newline character '\n' in the buffer for flexible input handling. The `>>` operator reads characters from the input until it encounters whitespace (space, tab, or newline). It is used to separate inputs.

    #include <iostream>

    using namespace std;

    int main(){
        string a;
        string b;
        cin >> a >> b;

        return 0;
    }

When we type "hello world", "hello\nworld", or "hello\tworld", these happen. 

1. Read "hello" into `a`.
2. Leave a newline character '\n' in the buffer.
3. Read "world" into `b`.
4. Leave a newline character '\n' in the buffer.

The example program should read "hello" into `a` and "world" into `b`, whichever hello-world one it get as an input. The behavior that handles whitespace characters indeed helps to separate inputs.

Be careful. **DO NOT** use `getline` right after `cin`! After `getline` encounters the remaining newline character in the buffer, it will stop reading immediately. It will result in an empty string for the `getline` input.

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

## `getline`
