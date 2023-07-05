# `.codeNN`
Insert a `.codeNN` directive before assembly language instructions to be run in NN-bit mode.
You can even switch GAS back to write normal MM-bit code with the `.codeMM` directive.

## `.codeNN` vs GCC's `-mNN` Option
Here are differences when you use the functions in XX-bit system.

| | .codeNN | -mNN |
|-| ------- | ---- |
| Type | Directive in GAS | GCC option |
| What will be<br>NN-bit | <ul><li>Assembler assumes the code<br>will be run in NN-bit</li><li>NN-bit machine code</li><li>NN-bit object</li></ul> | <ul><li>Include NN-bit C startup code</li><li>Link against NN-bit `libc`</li><li>NN-bit ELF file (executable)</li></ul> |

If you assemble a code using `.code32` in 64-bit system, without `-m32` GCC option, the machine code becomes 32-bit but the output ELF file becomes 64-bit. Because the system tries to run the 32-bit code in 64-bit mode, it will create run-time problems. It is hard to catch the problems since it does not produce any build-time errors.

Therefore, make use of the directive `.codeNN` only if you need to write some blocks of a code in NN-bit.

However, If you simply build NN-bit binaries in a XX-bit system, `.codeNN` won't be a good choice! Use `-mNN` option in GCC instead.
