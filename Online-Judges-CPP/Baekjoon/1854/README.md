# The `k`-th Shortest Path
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Use Dijkstra algorithm with saving `k` smallest time sums for every vertex.

### Note
* The problem requires to find "the k-th shortest path for City 1 → City X". You should not assume the first input will be always `-1`! Here's a counter-example for that where a path loops the City 1. (City 1 → City 1) Assume that a loop for the City 1 takes the time 3, and it is the only path in the example. In this case, the `5`-th shortest path from the City 1 to the City 1 takes the time `12`. It is not `-1` at all! The 1st path takes `0`. Since Mr. Kim always starts from the City 1, it means he can always reach to the City 1. We can find the `k`-th shortest path by repeating to add the loop time to 0, which is `3` in the example.

  | k | time |
  | -- | -- |
  | 1 | 0 |
  | 2 | 3 |
  | 3 | 6 |
  | 4 | 9 |
  | 5 | 12 |


</details>
