# Structure Padding & Structure Packing
Guide: http://www.catb.org/esr/structure-packing/

## Key Points
1. In a major class of modern ISAs, each C datatype except `char` has an **alignment requirement**.
If a type *Ty* is `n`-byte, *Ty*'s starting address `st_adr` must satisfy `st_adr % n == 0`.
2. `signed` and `unsigned` do not matter.
3. The more bytes a C datatype has, the stricter its alignment becomes.
4. **Pointer alignment** is the strictest, whether the machine is 32-bit or 64-bit.
5. (In C) Structure's address == 1st strucutre member's address. No leading padding.

## Note
C++ is almost the same with C, but classes looking like structures may ignore the "Key Points - Rule 5": their addresses are not always the same with those of their first members. Whether they do or not varies by compiler, or the way they are implemented.

## Example
### Example 3
    struct ST{
        char c1;
        short s1;
        char c2;
    };

`ST::s1` has the strictest alignment. To make the starting address of `ST::s1` even, add one-byte paddings after `ST::c1` and `ST::c2`.
The total size of `ST` is `6` bytes.

    struct ST{
        char c1;
        char pad1[1];   // padding
        short s1;
        char c2;
        char pad2[1];   // padding
    };

### Example 4
Here I swapped `ST::c2` and `ST::s1` from *Example 3*.

    struct ST{
        char c1;
        char c2;
        short s1;
    };

Since `ST::s1` starts on even address, there is no need to add any paddings.
The size of `ST` is `4` bytes.
