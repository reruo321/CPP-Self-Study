# [42883] Make the Biggest Number
How can we make the biggest number by removing `k` digits?

<details>
<summary><b>SPOILERS</b></summary>

**USE STACK.**

**+ Greedy algorithm**. Since the length of the answer is constant,
we should make the left digits as big as possible.

1. (Start from the 0th) Pick the `i`th digit, `num`, from the string.
2. Smash the smaller digits in the stack, by popping'em out!
If you see `top()` >= `num`, stop to `pop()`.
3. Push `num` into the stack.
4. Do step 1~3 again and again, until you remove `k` digits OR you reach the end of the string.

    4-a) If you have searched all digits but removed them less than `k`, pop() more from the stack.

5. Concatenate the numbers, from the stack's to the string's. (If you have not seen all parts of string.)
</details>
