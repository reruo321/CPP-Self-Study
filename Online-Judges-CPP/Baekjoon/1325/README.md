# Efficient Hacking
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Use BFS for each vertex in the graph to count the possible number of PC hacking. Store all BFS results to a vector, as if it is a dynamic programming. Find the maximum result among them and print all vertices that have the value.

### Note
The problem may need a simple algorithm, but its actual correct answer rate is below 20%! You must "efficiently" optimize your code to pass the test cases, or you won't pass from the 1% process. Here are some main ideas to do it.

1. USE `vector<vector<int>>` for representing this kind of graph in most problems. `vector<set<int>>` is unusual way to do that possible to occur lots of overheads comparing the 2D vector.
2. Directly store or apply ++ operation to the number of PC hacking in an answer vector for every starting PC.
3. Define some variables in global. Since it uses data segment in the memory, appropriate amount of using it helps the program to manage the memory.

</details>
