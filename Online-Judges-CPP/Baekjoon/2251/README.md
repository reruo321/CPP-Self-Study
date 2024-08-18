# Water Bucket
## Solution
<details>
<summary><b>SPOILERS</b></summary>

One of the solutions can use a graph search algorithm. Manage several status of water buckets A, B, C with a graph, where a status is treated as a vertex and no duplicated ones are allowed. You may pick various containers for the graph. I used `vector<vector<vector<bool>>>` to check if the status is available.

For example, let capaA, capaB, capaC be the capacity of three buckets. Let a, b, c be the current amount of water in the buckets. Suppose that capaA = 2, capaB = 4, capaC = 8. Since at first A and B are empty and C is full of water, then the initial status will be a = 0, b = 0, c = 8.

</details>
