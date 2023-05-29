# `-mpreferred-stack-boundary=num`
`-mpreferred-stack-boundary=num` attempts to keep the stack boundary aligned to a 2 raised to `num` (2^`num`) byte boundary.
In other words, you can set memory address `2^num`-byte aligned with this option.

GCC limits to pick `num` between `X` and 12, where `X` is either 3 or 4.
Note that the default argument is `4`, 16 bytes.

I also wrote about issues and solutions for the option when [num=2 or num=3](https://github.com/reruo321/OS-Self-Study/tree/main/_Appendix/GCC#-mpreferred-stack-boundarynum-is-not-between-x-and-12).

## How It Works?
**[Data alignment](https://github.com/reruo321/CPP-Self-Study/tree/master/CS/C/Data-Alignment)** really matters for using this option.

Compile a simple hello-world C code, `hello.c` several times, changing the `-mpreferred-stack-boundary=num` option.

    $ gcc -g hello.c -o hello_boundary_default
    $ gcc -g hello.c -o hello_boundary_2 -m32 -mpreferred-stack-boundary=2
    $ gcc -g hello.c -o hello_boundary_3 -mpreferred-stack-boundary=3
    $ gcc -g hello.c -o hello_boundary_4 -mpreferred-stack-boundary=4
    $ gcc -g hello.c -o hello_boundary_8 -mpreferred-stack-boundary=8
    $ gcc -g hello.c -o hello_boundary_12 -mpreferred-stack-boundary=12
    
