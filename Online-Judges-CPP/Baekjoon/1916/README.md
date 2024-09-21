# Minimum Cost
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Use **Dijkstra Algorithm** to find the minimum cost between two vertices. Use `priority_queue` (not `queue`!) to accurately find the paths. It can handle any situations that update shorter paths on early calculated vertices, which is not possible with the normal `queue`s. See [here](https://github.com/reruo321/CPP-Self-Study/tree/master/Online-Judges-CPP/Baekjoon/1753) to see an example for this.

</details>