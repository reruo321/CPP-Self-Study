# `-mpreferred-stack-boundary=num`
`-mpreferred-stack-boundary=num` attempts to keep the stack boundary aligned to a 2 raised to `num` (2^`num`) byte boundary.
In other words, you can set memory address `2^num`-byte aligned with this option.

GCC limits to pick `num` between `X` and 12, where `X` is either 3 or 4.
Note that the default argument is `4`, `2^4 = 16` bytes.

I also wrote about issues and solutions for the option when [num=2 or num=3](https://github.com/reruo321/OS-Self-Study/tree/main/_Appendix/GCC#-mpreferred-stack-boundarynum-is-not-between-x-and-12).

## How It Works?
**[Data alignment](https://github.com/reruo321/CPP-Self-Study/tree/master/CS/C/Data-Alignment)** really matters for using this option.

I assume that the environment is 64-bit, so adding `-m32` option is needed when `num`=2. Default value of the argument `num` is `4` in both 32-bit and 64-bit machines.

Write and compile a simple hello-world C code, `hello.c` several times, changing the `-mpreferred-stack-boundary=num` option. I set the buffer size `123` in the example code.
(Note: The source `hello.c` I uploaded is vulnerable to buffer overflow attack! It is also used in my buffer overflow study.)

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

### Examples
#### 1. `num=12`
Let's examine `hello_boundary_12` first. In the main function,

![main_b_12](https://github.com/reruo321/CPP-Self-Study/assets/48712088/d3a89307-4b0f-455a-a0d7-7f446fabd93b)

    0x0000555555555222 <+8>:	and    $0xfffffffffffff000,%rsp
    0x0000555555555229 <+15>:	sub    $0x1000,%rsp
    
`%rsp` is masked and subtracted to be a multiple of 2^12 = 0x1000.

When `main()` calls `fun()` and `%rbp` is pushed, 

![main_b_12_callee](https://github.com/reruo321/CPP-Self-Study/assets/48712088/509e18ae-f619-422e-9f84-fe9b9c2a4595)

`%rsp` changes from `0x7fffffffc000` to `0x7fffffffbff0`. (Each `push` subtracts `%rsp` 8 bytes.)
Although `%rsp` is not to be a multiple of 0x1000 temporarily,

    0x0000555555555191 <+8>:	sub    $0x1000,%rsp
    0x0000555555555198 <+15>:	orq    $0x0,(%rsp)
    0x000055555555519d <+20>:	sub    $0x1000,%rsp
    0x00005555555551a4 <+27>:	orq    $0x0,(%rsp)
    0x00005555555551a9 <+32>:	sub    $0xff0,%rsp
    
`%rsp` becomes `0x7fffffff9000` after three `sub`s, which make it a multiple of 0x1000 again!

![main_b_12_callee3](https://github.com/reruo321/CPP-Self-Study/assets/48712088/cc1e765b-5bd8-4a62-9698-ddce50326617)

We learn that when the program allocates buffer on the stack, its size does not always follow the buffer size specified by the C source code, `123`. Instead, it can allocate more than the buffer size to make `%rsp` to be a multiple of `2^num`, so that it makes the stack `2^num`-aligned.

Now let's examine other cases.

#### 2. `num=2`
##### main()
![main_b_2](https://github.com/reruo321/CPP-Self-Study/assets/48712088/3b695a7f-cc00-4155-8a0d-bcefd6e33037)

Because of `-m32`, the executable file was compiled in 32-bit mode. No `%rsp` here. Instead, `%esp` is `0xffffd0d8`, multiple of `2^2 = 4`, in my GDB.

##### fun()
![fun_b_2](https://github.com/reruo321/CPP-Self-Study/assets/48712088/b4d4625d-6699-4336-8f72-e6e2c97845fb)

Statements:

1. `%esp` was the multiple of 4 before calling `fun()`.
2. Each push subtracts 4 from `%esp`.
3. At 0x565561c1, `0x84` (132) is subtracted from `%esp` to allocate memory for buffer.

Conclusion: After calling `main()`, `%esp` is always a multiple of `4` in this program.

However, you may doubt and say: "Hey, there is no guarantee that the stack is always aligned when calling the main function, like your Statement 1. **If `%esp % 4 != 0` at the beginning, it will ruin your proof!**"

Okay, let's talk about this later after seeing all other programs.

#### 3. `num=3`
##### main()
![main_b_3](https://github.com/reruo321/CPP-Self-Study/assets/48712088/7208e9c1-9345-45e1-8d22-5e56e5ac65df)

    0x0000000000001208 <+8>:	sub    $0x10,%rsp

We should keep the stack boundary aligned to a `8` byte boundary. Assuming that `%rsp % 8 == 0`, subtracting `0x10` (16) from it is okay.

##### fun()
![fun_b_3](https://github.com/reruo321/CPP-Self-Study/assets/48712088/b7be8eb6-9b08-4472-9b82-3089081a95b4)

    0x0000000000001191 <+8>:	and    $0xfffffffffffffff0,%rsp
    0x0000000000001195 <+12>:	sub    $0xa0,%rsp


#### 4. default (`num=4`)
##### main()
![main_b_default](https://github.com/reruo321/CPP-Self-Study/assets/48712088/d5badf21-a4e9-4737-8d3e-d8a7732e2d42)

    0x0000000000001204 <+8>:	sub    $0x10,%rsp

##### fun()
![fun_b_default](https://github.com/reruo321/CPP-Self-Study/assets/48712088/8f36f8c8-b9ce-4552-b8a3-1189c04b0f8c)

    0x0000000000001191 <+8>:	sub    $0xa0,%rsp

#### 5. `num=8`
##### main()
![main_b_8](https://github.com/reruo321/CPP-Self-Study/assets/48712088/f27ee03c-6990-40e0-aa92-60c1d2c03726)

    0x000000000000120a <+8>:	mov    $0x0,%spl
    0x000000000000120d <+11>:	sub    $0x100,%rsp

##### fun()
![fun_b_8](https://github.com/reruo321/CPP-Self-Study/assets/48712088/dbde4a20-ecbb-4a8f-be3a-f43944a56a53)

    0x0000000000001191 <+8>:	sub    $0x2f0,%rsp

### \_start()
