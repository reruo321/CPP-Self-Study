# Tree Diameter
## Solution
<details>
<summary><b>SPOILERS</b></summary>
  
1. Find the farthest vertex X from a random start vertex with BFS. It must be one of two vertices that makes the tree diameter.
2. Run BFS again with the vertex X to find the farthest vertex Y. The distance between X and Y is the tree diameter.

</details>
