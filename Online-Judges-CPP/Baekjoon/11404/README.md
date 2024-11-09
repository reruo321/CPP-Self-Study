# Floyd

## Solution
Use Floyd-Warshall algorithm to find the shortest path for all vertices' pairs in a graph.

### Note
* If you want to find the shortest path between A and Z, you will examine A ~ X ~ Z, where X is a intermediate vertex between A and Z. You must check if both A ~ X AND X ~ Z are not the maximum limit value, otherwise either of them will be not valid path.
