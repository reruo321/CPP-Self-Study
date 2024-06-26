# Good
* Problem Link: https://www.acmicpc.net/problem/1253
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Using two pointers that point to the start/end of the whole set + Selecting a number to compare with the addition of the start and the end, find the sets that are equal to the target number. For example, in {1, 2, 3}, we can get an answer pair when selecting 3 as a target number and pointing 1 and 2 as start/end pointers.

### Note
The number to compare with the addition MUST NOT BE the same as the start/end numbers to add. The number in this case must be excluded to filter some answer candidate pairs. For example, in {0, 0, 0}, when selecting the first 0 as the comparing number and adding the first one and the second one, the addition is 0 so it almost can be an answer. However, it actually should be excluded as the answer, since the 'first 0' to add is the same thing as the number to compare, 'first 0'! If we select the first 0 to compare, and add the second 0 and the third 0, the case can be an answer since they are all different numbers, even all of their values are 0.

</details>
