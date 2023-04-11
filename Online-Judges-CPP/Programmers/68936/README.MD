# [68936] Quardtree-Compression & Count Numbers
The problem compresses the input array into multiple quardtrees.
(For me) it was very annoying to track the state of each quardtree!

<details>
<summary><b>SPOILERS</b></summary>

I used `set<pair<int, int>>` to track upper-left parts of quardtrees.

1. If the input is 1x1, just return the answer.
2. Divide the input into 2x2 quardtrees.

    a. Compare four values in a quardtree, `arr[i][j]`, `arr[i+1][j]`, `arr[i][j+1]`, `arr[i+1][j+1]`.

    - i) If they are the same, add the index of upper-left square to the pair set, `(i, j)`. The index will be the representative of the conquered square. Add `1` to the corresponding position of the answer.
    
    - ii) If not, just add the numbers of 0 and 1 to the answer.

3. Until the set becomes empty (= no more conquer), repeat to conquer on 4x4, 8x8, ... `arr.size()`x`arr.size()`.

    a. Let's check if all four parts in a quardtree are ready to be conquered. They must be in the pair set.

    - i) If a part is available, erase it from the set.

    - ii) If a part is unavailable, mark the quardtree not to be conquered.

    b. If all indices are available, compare four values. You can take them from the original input array.

    - i) If they are the same, subtract `3` from the corresponding position of the answer. (If four parts are conquered, the number of the value becomes 4 -> 1.) Also, add the index of the upper-left part.

    c. Repeat step 3.

## Graph Explanation

</details>
