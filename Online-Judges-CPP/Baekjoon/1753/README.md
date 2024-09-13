# Shortest Path
## Solution
<details>
<summary><b>SPOILERS</b></summary>

**Dijkstra Algorithm** is a very good algorithm to find the shortest path between two vertices in a graph. You must use `priority_queue`, not a normal `queue` for the Dijkstra algorithm!!! With just `queue`, you cannot greedily search the shortest paths or upgrade some later shorter paths for the algorithm.

### Example
This is an example which becomes a counter-example of the wrong Dijkstra algorithm using `queue`, and also example of the correct one with `priority_queue`.

</details>
