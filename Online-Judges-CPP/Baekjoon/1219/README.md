# Oh Man Shik's Concern

## Solution
<details>
<summary><b>SPOILERS</b></summary>

Modify the **Bellman-Ford-Moore** algorithm.

1. Set all vertice values to minimum. (`std::numeric_limits<long long>::min()`)
2. Starting from the source vertex, loop all edges for `N-1` times to find the maximum money of every vertex.
3. Loop all the edges for `N-1` times to find the vertices that updates the maximum money. If a vertex updates its value even after Step 2, it means it is in a positive cycle. Mark the destination as maximum. (`std::numeric_limits<long long>::max()`)
4. Find if the destination vertex value becomes the maximum.

</details>
