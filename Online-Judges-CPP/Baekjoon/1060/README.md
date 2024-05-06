# Good Number (in progress)
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Manage the list of the best n good numbers with a priority queue, which sorts a struct of good numbers, `Goodnum`, in descending order. (Worst becomes the top.) Pop out the worst one if the queue has more than n elements. After checking all numbers, move all contents of queue to a vector and print them in ascending order.

### Notes
* Suppose that `s1` and `s2` are numbers in S where `s2` - `s1` = 2. For example, there's a set S = {s1, s2} where `s1` = 10 and `s2` = 12. Then `s3` = s2 - 1 has 0 good sets because both sides of `s3` are blocked by the numbers in S, `s1` and `s2`. Therefore, `s3` can have high priority because of its small number (0) of good sets.

</details>
