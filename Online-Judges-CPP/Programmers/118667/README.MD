# [118667] Two Queues with the Same Sum
It seems to be annoying to see the moving of the numbers...

## Solution
<details>
<summary><b>SPOILERS</b></summary>

The sequence of the numbers is **uniform**.

One important thing to know: It takes 1 second for `10^8` operations.
The maximum value of `queue1.size()` and `queue2.size()` is `300,000`.
Therefore, using algorithms taking O(n^2) won't be able to afford the worst `9×10^10` operations on 10-second limit!

Rather than using brute-force with double for-loops for all numbers, we'd better to simulate with real `queue`s.
(Note: The input \*queue\*s are actually `vector`s!)

Let's see how the numbers move. Suppose that there are two queues:
> [1 2 3 4]

> [5 6 7 8]

I will do pop-and-push on queue1, queue2, queue1, queue2, queue1, queue2, queue1, queue2.
(DIY with some drawing tools!)

(1st try)

> [2 3 4]

> [5 6 7 8 1]

(2nd try)

> [2 3 4 5]

> [6 7 8 1]

(...after 8th try)

> [5 6 7 8]

> [1 2 3 4]

</details>
