# Oh Man Shik's Concern

## Solution
<details>
<summary><b>SPOILERS</b></summary>

Modify the **Bellman-Ford-Moore** algorithm.

1. Set all vertice values to MIN. (`std::numeric_limits<long long>::min()`)
2. Starting from the source vertex, loop all edges for `N-1` times to find the maximum money of every vertex.
3. If the destination vertex value is the MIN, it cannot be reached from the source vertex. Therefore, print "gg". If it has some other value, go to the next step.
4. Loop all the edges for `N-1` times to find the vertices that update their maximum money. If a vertex updates its value even after Step 2, it means it is in a positive cycle. Mark the destination as MAX. (`std::numeric_limits<long long>::max()`)
5. Check if the destination vertex value is the MAX. If it is, print "Gee". If not, print the value.

</details>
