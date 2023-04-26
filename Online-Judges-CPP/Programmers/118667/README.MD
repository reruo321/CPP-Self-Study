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

### Pattern
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

You may notice that all numbers have the specific order.

> 1 2 3 4 5 6 7 8 / 1 2 3 4 5 6 7 8 / ...

Therefore, you do not need to worry about some complicated crossing pop-and-push situations.

### Algorithm
1. Get the sum of queue1, `q1`, and queue2, `q2`.

    a. If `q1 + q2` is odd, return `-1`. Since all numbers in the queues are integers, the mean must be also an integer.

2. Get the `mean` of queues by `(q1 + q2) / 2`.

3. (If the inputs are `vector`s) Create real `queue`s, `que1` and `que2`, and fill them with their original numbers.

4. Push back a special number into `que1` to notify the end of the pop-and-push loop. Be careful not to add/subtract it to/from `q1`. It must be out of input numbers' range. I chose `INT_MAX`.

5. Loop until you find the answer, or the special number is the front of `que2`. We will track only `q1`, not `q2`.

    a. If the special number is the front of `que1`, pop-and-push it. Do not count its pop-and-push!

    b. If `q1 > mean`, pop-and-push the front of `que1`.

    c. If `q1 < mean`, pop-and-puah the front of `que2`.

    d. If `q1 == mean`, return the total number of pop-and-push.

6. If the loop is finished without `q1 == mean`, return `-1`.
</details>
