# Input and Output in C++
## `<iostream>`
### `cin`
`cin` leaves a newline character '\n' in the buffer for flexible input handling. The `>>` operator reads characters from the input until it encounters whitespace (space, tab '\t', or newline '\n'). It is used to separate inputs.

    #include <iostream>

    int main(){
        std::string a;
        std::string b;
        std::cin >> a >> b;

        return 0;
    }

When we type "hello world", "hello\nworld", or "hello\tworld", these steps happen. 

1. Read "hello" into `a`.
2. Leave a newline character '\n' in the buffer.
3. Read "world" into `b`.
4. Leave a newline character '\n' in the buffer.

The example program should read "hello" into `a` and "world" into `b`, whichever hello-world one it get as an input. The behavior that handles whitespace characters indeed helps to separate inputs.

Be careful. **DO NOT** use `getline` right after `cin`! After `getline` encounters the remaining newline character in the buffer, it will stop reading immediately. It will result in an empty string as the `getline` input.

#### `cin.ignore()`

    #include <iostream>

    std::string str;
    std::cin.ignore(N, C) >> str;

Ignores up to `N` characters OR until it encounters the specified delimiter character `C`. If `C` is not specified (the default is `EOF`), it will ignores the first `N` characters.

When using `std::cin` and then `std::getline()`, 

##### Example 1
* N=3
* C is not specified
* Input: "abcdefgh"

> str: defgh
##### Example 2
* N=3
* C='e'
* Input: "abcdefgh"

> str: defgh

##### Example 3
* N=7
* C is not specified
* Input: "abcdefgh"

> str: h
##### Example 4
* N=7
* C='e'
* Input: "abcdefgh"

> str: fgh

##### Example 5
* N=20
* C is not specified
* input:

  "abcde

  fghij

  klmno

  pqrst"

> str: rst

##### Example 6
* N=20
* C='h'
* input:

  "abcde

  fghij"

> str: ij

### `cout`

    #include <iostream>

    using namespace std;

    int main(){
        cout << "Hello, World!" << endl;
        return 0;
    }

### `getline`

    #include <iostream>

    using namespace std;

    int main(){
        string line;
        getline(cin, line);

        return 0;
    }

It reads a line until it meets a newline character, '\n'.

Be careful. **DO NOT** use `getline` right after `cin`! After `getline` encounters the remaining newline character in the buffer, it will stop reading immediately. It will result in an empty string for the `getline` input.

### Usage
1. When the number of input lines is not specified (Text files, some programming problems, ...)

## <sstream>
### istringstream

    #include <sstream>

    string line = "This is great";
    string str_this, str_is, str_great;

    std::istringstream iss(line);
    iss >> str_this >> str_is >> str_great;

### ifstream

