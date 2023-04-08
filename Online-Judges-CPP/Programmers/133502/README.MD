# [133502] Burger Maker
This is the problem I tried to use **[Boyer-Moore-Horspool](https://github.com/reruo321/Online-Judges-CPP/tree/master/Online-Judges-CPP/_Algorithms#boyer-moore-horspool)** to solve.
## Solution
If you are going to use `string` to solve this problem like me, any substring finding algorithms would be okay.
Actually, there is more important trick you should know...
<details>
<summary><b>SPOILERS</b></summary>

**DO NOT REPEAT unnecessary search!**

Do not start again from the 0th position, when you are in the middle of the string!
Even if you try to find another burger after making one, just go back `2` steps from the current position.

You may not need to see the string parts you have seen over and over again.
They are confirmed to not have a full burger, but might have some possible parts.
Leave them, until you pop out burgers and go back to them.

Suppose that there are ingredients like:
> 3 3 3 3 3 1 2 1 2 3 1 3 1

You do not need to start to search from the 0th ingredient again and again,
since you already checked that there is no burger in `3 3 3 3 3 1 2`.

How about the situation after making a burger?
> 3 3 3 3 3 1 2 [@1 2 3 1] 3 1

Suppose your cursor's position is `@` after removing,
> 3 3 3 3 3 1 2 @3 1

Then going back just `2` steps is sufficient to find another burger.
> 3 3 3 3 3 [@1 2 3 1]

### Why just 2 Steps?
Let's see some examples to check the relationship between making a burger and the cursor's position.
We will find the maximum steps to go back to find the next burger.

1. Stay
> 3 [@1 2 3 1] 1 2 3 1

> 3 @1 2 3 1

2. Another stay (You will meet an exception if you go back!)
> (front of the string) [@1 2 3 1] 3 3 3 3

> (front of the string) @3 3 3 3

3. Going back `1` step
> 1 [@1 2 3 1] 2 3 1

> 1 @2 3 1

4. Going back `2` steps
> 1 2 [@1 2 3 1] 3 1

> 1 2 @3 1

This is an impossible situation, because there is already a burger before `[ ]`!
> 1 2 3 [@1 2 3 1] 1 --> Impossible!

> 1 2 3 @ 1

Here is what it should be:
> [1 2 3 1] 2 3 1 1

Therefore, no need to see before `3` or more steps, after popping out a burger.

</details>
