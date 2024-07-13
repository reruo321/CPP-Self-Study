# Cocktail
## Solution
<details>
<summary><b>SPOILERS</b></summary>

The problem is the combination of GCD & LCM and one-way DFS.

### Steps
1. Before we start the DFS, we should multiply all prime numbers from all ratios, excluding just GCD of each ratio. For example, there are two ratios as 3:1 and 6:4. Then we can get the value of the DFS starting node.

$$ start = (3 × 1 / GCD(3, 1)) × (6 × 4 / GCD(6, 4))
= 3 × 12 = 36 $$

2. As we assign it to the start node of the DFS, we can multiply or divide it into some constituting numbers according to the ratio.

</details>
