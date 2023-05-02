# String
## Header
    #include <string>
## Operators
There are various operators supported on string.

***operator=*** (assignment), ***operator[]*** (get character), ***operator+=*** (appending),
***operator+*** (concatenation), ***operator>>*** (istream), ***operator<<*** (ostream).

***Relational operators*** (such as operator==, operator<=) can be also used.
## *append()*
    string& append (const string& str);
    string& append (const string& str, size_t subpos, size_t sublen = npos);
### Example

    string str1 = "Wow! ";
    string str3 = "Good ";
    string str5 = "What the ";
    string str2 = "Hello World";
    
    str1.append(str2);  // str1 == "Wow! Hello World"
    str3.append(str2, 6);  // str3 == "Good World"
    str5.append(str2, 0, 4);  // str5 == "What the Hell"

## *substr()*
    string substr (size_t pos = 0, size_t len = npos) const;
### Example
    string str1 = "Hello World!";
    string str2 = str1.substr(0, 4);    // str2 == "Hell"

## *find()*
Very useful to parse or find something in the string.
### Example
    size_t found = str.find("#");
    string my_string = str.substr(0, found);
## *push_back()*
    str.push_back('X');
    str.push_back('5');
## *pop_back()*
    str.pop_back();
## *size()*
***size()* = *length()*** in string.
## *compare()*
    if(str1.compare(str2) == 0)
        cout << "They are the same." << endl;
    if(str1.compare(str3) != 0)
        cout << "They are different." << endl;

## *npos*
    static const size_t npos = -1;

`npos` is a static member constant value with the maximum value for the type `size_t`.

### Usage
1. As a value for ***len/sublen*** parameter: **Until the end of the string**.
2. As a return value: Usually "No matches".

## Notes
**BE CAREFUL** while dealing with chars and strings together!

Suppose that you want to make a string `hi AB`,
by concatenating some chars and a string.
    
    char a = 'A';
    char b = 'B';
    string str = "hi ";
    
    str += a + b;   // OH NO!
    
    cout << str << endl;

However, the result is `hi �`.
The precedence of the operator `+` is higher than that of `+=`.
Therefore, `a+b` is done first.

    str += to_string(a) + to_string(b);   // No.

The second try is not good neither, since its output is `hi 6566`.

    str = str + a + b;   // Right!

This is one of the right answer. As the associativity of `+` is left-to-right,
it will add chars to the string in sequence.

Also, pay attention to **parameters** for some member functions,
if there is a char! They need `n` before a char argument,
which means the number of the characters.

    // The functions which use "n" as a parameter.
    str.append(n, '*');
    str.assign(n, '*');
    str.insert(0, n, '*');
    str.replace(0, 1, n, '*');

The other functions such as *string::push_back()* do not need to put the number.
