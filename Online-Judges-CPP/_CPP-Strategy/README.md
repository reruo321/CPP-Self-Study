# C++ Strategy for Online Judges
The document is a C++ quick guide especially for online judges.

## Avoiding Time Limit Exceeded Problem
1. Analyze time constraints. 1-sec time limit will allow your process to run **10^8** operations.
2. No 4 or more nested loops if N >= 100 for 1-sec time limit. Because of Tip 1, it will cause more than 10^8 operations and time-over.
3. Use faster I/O method. Use *printf()*/*scanf()* instead of *cin()*/*cout()*.
4. Try to reduce loops in your program.

## Others
* When you use `unsigned` integer types, such as `size_t`, **BE CAREFUL** while doing some calculation!
For example, when `size_t size = 3`, `size - 5` will make the result very-very big, since it causes underflow!
