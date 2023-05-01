# Structure Padding & Structure Packing
Guide: http://www.catb.org/esr/structure-packing/

## Key Points
1. In a major class of modern ISAs, each C datatype except `char` has an **alignment requirement**.
If a type *Ty* is `n`-byte, *Ty*'s starting address `st_adr` must satisfy `st_adr % n == 0`.
2. `signed` and `unsigned` do not matter.
3. The more bytes a C datatype has, the stricter its alignment becomes.
4. Because of the Point 3, **pointer alignment** is the strictest, whether the machine is 32-bit or 64-bit.

## Example
### Example 3
    struct S1{
        char c1;
        short s1;
        char c2;
    };

`S1` 

    struct S2{
        char c1;
        char c2;
        short s1;
    };
