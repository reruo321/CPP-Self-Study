# Joon Hwan's Balance
## Solution
<details>
<summary><b>SPOILERS</b></summary>
Use backtracking algorithm for permutation. Since the problem requires lots of operations for the biggest answer, we should optimize the program very tightly to pass all test cases.

### Steps
The biggest answer would need \$2^9 * 9!\$, where \$2^9\$ asks "Do I put a weight on the left or on the right?" and \$9!\$ asks "What is the order of weights?". Therefore, we must decrease the operations as many as we can.


</details>
