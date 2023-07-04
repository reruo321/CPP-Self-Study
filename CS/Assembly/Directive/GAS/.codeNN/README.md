# `.codeNN`
Insert a `.codeNN` directive before assembly language instructions to be run in NN-bit mode.
You can even switch GAS back to write normal MM-bit code with the `.codeMM` directive.

## `.codeNN` vs GCC's `-mNN` Option
Here are differences when you use the functions in XX-bit system.

| | .codeNN | -mNN |
|-| ------- | ---- |
| What are NN-bit |
