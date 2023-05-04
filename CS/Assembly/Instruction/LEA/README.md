# LEA
**LEA(Load Effective Address)** instruction is used to put an "effective address" into the destination.
Although it has similar form with `MOV`, it just computes address instead of reading from it.

## Effective Address
**Effective address** is 

## Usage
1. To copy an effective address to destination, which is done with `&` operation in C.

The below shows some part of the figure 3.32 codes from the CS book. It uses `LEA` to store addresses as arguments.

    # C code: char x4 = 4;
    # Description: Store &x4 as argument 8, and call other function.
    
    # Store 4 in &x4
    movb $4, 17(%rsp)

    # Create &x4
    leaq 17(%rsp), %rax
    
    # Store &x4 as argument 8
    movq %rax, 8(%rsp)

2. To create a pointer for memory reference.
3. To simply descript normal arithmetic operations. Compiler can use `LEA` even if there is no effective address.
