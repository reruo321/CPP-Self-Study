# Range Sum
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Use **Segment Tree** algorithm to efficiently handle the sums of various ranges. While prefix sum algorithm takes O(N) for computing every range sum, the segment tree only takes O(logn) to do it. Moreover, the segment tree simply gets a new query result after changing data, which cannot be done by the prefix sum algorithm.

### Note
* Run a loop to take input lines containing three numbers for `M + K` times. **Do not** count 1-commands and 2-commands separately! It will produce many overheads so it will occur time limit failure.

</details>
