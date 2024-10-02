# The `k`-th Shortest Path
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Use Dijkstra algorithm with saving `k` smallest time sums for every vertex.

### Note
* The problem requires to find "the k-th shortest path for City 1 → City X". You should not assume the first input will be always `-1`! Here's a counter-example for that that a path only loops the City 1. (City 1 → City 1) Assume that the City 1 has a loop that takes 3. In this case, the `5`-th shortest path from the City 1 to the City 1 takes the time `12`. It is not `-1` at all!

  | k | time |
  | -- | -- |
  | 1 | 0 |
  | 2 | 3 |
  | 3 | 6 |
  | 4 | 9 |
  | 5 | 12 |


</details>
