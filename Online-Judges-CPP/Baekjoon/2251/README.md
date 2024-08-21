# Water Buckets
## Solution
<details>
<summary><b>SPOILERS</b></summary>

One of the solutions can use a graph search algorithm. Manage several status of water buckets A, B, C with a graph, where a status is treated as a vertex and no duplicated ones are allowed. You may pick various containers for the graph. I used `vector<vector<vector<bool>>>` to check if the status is available.

### Example
Let `capaA`, `capaB`, `capaC` be the capacity of three buckets. Let `a`, `b`, `c` be the current amount of water in the buckets. And let `vec` be a `vector<vector<vector<bool>>>`, where the size is `(capaA + 1) × (capaB + 1) × (capaC + 1)`. Then we can assign `vec` like `capaA + 1, vector<vector<bool>>(capaB + 1, vector<bool>(capaC + 1, false))`. Suppose that `capaA` = 2, `capaB` = 4, `capaC` = 8. Since at first A and B are empty and C is full of water, then the initial status will be `a` = 0, `b` = 0, `c` = 8. We can then register the status as `vec.at(0).at(0).at(8) = true`. The main algorithm would be the same as that of normal BFS. If a status is already checked `true`, do not put it into a queue and just throw away, so that the program would not search the same process again. After the queue being empty, get the answer by simply counting the number of `true`s in `vec.at(0)`.

</details>
