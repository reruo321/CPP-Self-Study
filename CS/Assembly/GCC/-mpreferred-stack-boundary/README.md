# `-mpreferred-stack-boundary=num`
`-mpreferred-stack-boundary=num` attempts to keep the stack boundary aligned to a 2 raised to `num` (2^`num`) byte boundary.
In other words, you can set memory address `2^num`-byte aligned with this option.

GCC limits to pick `num` between `X` and 12, where `X` is either 3 or 4.
Note that the default argument is `4`, 16 bytes.

I also wrote about issues and solutions for the option when [num=2 or num=3](https://github.com/reruo321/OS-Self-Study/tree/main/_Appendix/GCC#-mpreferred-stack-boundarynum-is-not-between-x-and-12).

## How It Works?
**[Data alignment](https://github.com/reruo321/CPP-Self-Study/tree/master/CS/C/Data-Alignment)** really matters for using this option.

I assume that the environment is 64-bit, so adding `-m32` option is needed when `num`=2. Default value of the argument `num` is `4` in both 32-bit and 64-bit machines.

Compile a simple hello-world C code, `hello.c` several times, changing the `-mpreferred-stack-boundary=num` option.
(Note: The source `hello.c` I uploaded as an example is vulnerable to buffer overflow attack! It is also used in my buffer overflow study.)

    $ gcc -g hello.c -o hello_boundary_default
    $ gcc -g hello.c -o hello_boundary_2 -m32 -mpreferred-stack-boundary=2
    $ gcc -g hello.c -o hello_boundary_3 -mpreferred-stack-boundary=3
    $ gcc -g hello.c -o hello_boundary_8 -mpreferred-stack-boundary=8
    $ gcc -g hello.c -o hello_boundary_12 -mpreferred-stack-boundary=12
    
Disassemble each program, set a breakpoint at `fun(argv\[1\]);`, and track `%rsp`.

    $ gdb hello_boundary_X

    (gdb) b main
    (gdb) r
    (gdb) disas main
    (gdb) i r rsp
    (gdb) si
    (gdb) si
    ...

I will see `hello_boundary_12` as an example. In the main function,

![main_b_12](https://github.com/reruo321/CPP-Self-Study/assets/48712088/d3a89307-4b0f-455a-a0d7-7f446fabd93b)

    0x0000555555555222 <+8>:	and    $0xfffffffffffff000,%rsp
    0x0000555555555229 <+15>:	sub    $0x1000,%rsp
    
`%rsp` is masked and subtracted to be multiple of 2^12 = 0x1000.

When `main()` calls `fun()` and `%rbp` is pushed, 

![main_b_12_callee](https://github.com/reruo321/CPP-Self-Study/assets/48712088/509e18ae-f619-422e-9f84-fe9b9c2a4595)

`%rsp` changes from `0x7fffffffc000` to `0x7fffffffbff0`.

