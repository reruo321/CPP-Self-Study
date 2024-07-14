# Cocktail
## Solution
<details>
<summary><b>SPOILERS</b></summary>

One of the solutions is the combination of GCD & LCM and one-way DFS.

### Steps
1. Before we start the DFS, we should multiply all prime numbers from all ratios, excluding just GCD of each ratio. For example, there are two ratios as 6:4 and 3:1. Then we can get the value of the DFS starting node, v0.

$$ n0 = (3 × 1 / GCD(3, 1)) × (6 × 4 / GCD(6, 4))
= 3 × 12 = 36 $$

2. As we assign it to the start node of the DFS, we can multiply or divide it into some constituting numbers according to the ratio. If the start node n0 has the value v0 = 36, and if the ratio of v0 : v1 = 6 : 4, then we can find the value of n1.

$$ v1 = 36 × 4 / 6 = 24 $$

</details>
