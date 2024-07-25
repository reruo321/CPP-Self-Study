# Cocktail
## Solution
<details>
<summary><b>SPOILERS</b></summary>

One of the solutions is the combination of GCD (Greatest Common Divisor) & LCM (Least Common Multiple) and one-way DFS.

### Steps
1. Before we start the DFS, we should multiply all prime numbers from all ratios, excluding just GCD of each ratio. Then we can divide node values into any prime divisors brought from any ratios. For example, there are two ratios as 6:4 and 3:1. Then we can get the value of the DFS starting node. You can select any node as the starting node. Let v0 be the value of the 0-th starting node, n0.

$$ n0 = (3 × 1 / GCD(3, 1)) × (6 × 4 / GCD(6, 4))
= 3 × 12 = 36 $$

2. As we assign it to the start node of the DFS, we can multiply or divide it into some constituting numbers according to the ratio. If the start node n0 has the value v0 = 36, and if the ratio of v0 : v1 = 6 : 4, then we can find the value of n1.

$$ v1 = 36 × 4 / 6 = 24 $$

3. Divide all node values into their GCD, so that we can get the final answer numbers. Loop the nodes to find their GCD, and divide them into it with another loop. If the values of the nodes are $v1 = 24$, $v2 = 30$, $v3 = 36$, we can find the GCD 6 with a loop. Dividing the nodes into GCD, we can get the final values, 4, 5, 6.

$$ v1 = 24 / 6 = 4 $$

$$ v2 = 30 / 6 = 5 $$

$$ v3 = 36 / 6 = 6 $$

</details>
