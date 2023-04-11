# [68936] Quardtree-Compression & Count Numbers
The problem compresses the input array into multiple quardtrees.
(For me) it was very annoying to track the state of each quardtree!

<details>
<summary><b>SPOILERS</b></summary>

I used divide-and-conquer algorithm, and `set<pair<int, int>>` and the upper-left parts of quardtrees to check information.

1. If the input is 1x1, just return the answer.
2. Divide the input into 2x2 quardtrees.

    a. Compare four values in a quardtree, `arr[i][j]`, `arr[i+1][j]`, `arr[i][j+1]`, `arr[i+1][j+1]`.

    - i) If they are the same, insert the index of upper-left square into the pair set, `(i, j)`. The index will be the representative of the conquered square. Add `1` to the corresponding position of the answer.
    
    - ii) If not, just add the numbers of 0 and 1 to the answer.

3. Until the set becomes empty (= no more conquer), repeat to conquer on 4x4, 8x8, ... `arr.size()`x`arr.size()`.

    a. Let's check if all four parts in a quardtree are ready to be conquered. They must be in the pair set.

    - i) If a part is available, erase its index from the set.

    - ii) If a part is unavailable, mark the quardtree not to be conquered.

    b. If all indices are available, compare four values. You can take them from the original input array.

    - i) If they are the same, subtract `3` from the corresponding position of the answer. (If four parts are conquered, the number of the value becomes 4 -> 1.) Also, insert the index of the upper-left part into the set.

    c. Repeat step 3.

## Graph Explanation
Suppose that there is an input like this:

| 0 | 0 | 1 | 1 | 0 | 0 | 0 | 0 |
|-|-|-|-|-|-|-|-|
| 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |
| 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |
| 1 | 0 | 1 | 0 | 1 | 0 | 1 | 0 |

### 1. 1x1

The input is not 1x1. Therefore, let's start to divide-and-conquer it!

### 2. 2x2

#### Example 1
(0, 0), (1, 0), (0, 1), (1, 1)

You can find that all four values are the same `0`.

Insert `(0, 0)` into the pair set. Also `answer[0] += 1`.

| | (Row 0) | (Row 1) |
|-|-|-|
| (Col 0) | 0 | 0 |
| (Col 1) | 0 | 0 |

* Result set: (0, 0)

#### Example 2
(0, 2), (1, 2), (0, 3), (1, 3)

The four values are not the same!

DO NOT insert anything into the set. There are one `0` and three `1`s. Do `answer[0] += 1`, `answer[1] += 3`.

| | (Row 2) | (Row 3) |
|-|-|-|
| (Col 0) | 1 | 1 |
| (Col 1) | 0 | 1 |

* Result set: (0, 0)

### 3. 4x4
After processing all 2x2 quardtrees, keys in the pair set will be:

(0, 0), (2, 0), (2, 2), (0, 4), (0, 6), (2, 4), (2, 6)

(Note: I didn't consider the order of the set's keys.)
#### Example 1
Let's see the first 4x4 part of the input.

| | (Row 0) | (Row 1) | (Row 2) | (Row 3) |
|-|-|-|-|-|
| (Col 0) | **0** |   |   |   |
| (Col 1) |   |   |   |   |
| (Col 2) | **1** |   | **1** |   |
| (Col 3) |   |   |   |   |

For example, since the index `(0, 0)` is in the pair set,
we know the 2x2 quardtree with `(0, 0)` has been conquered.
We can also notice the value is `0`, by checking `arr[0][0]`.

In contrast, we cannot find `(0, 2)` from the set, because the 2x2 quardtree with `(0, 2)` has not been conquered.
By missing one of four indices, `(0, 2)`, from the set, we cannot conquer this 4x4 quardtree.

There is no effect on the answer!
Just discard `(0, 0)`, `(2, 0)`, `(2, 2)` from the set.

* Result set: (0, 4), (0, 6), (2, 4), (2, 6)
#### Example 2

| | (Row 4) | (Row 5) | (Row 6) | (Row 7) |
|-|-|-|-|-|
| (Col 0) | **0** |  | **0** |  |
| (Col 1) |  |  |  |  |
| (Col 2) | **0** |  | **0** |  |
| (Col 3) |  |  |  |  |

Applying the same idea, we easily know we can conquer this tree.
All four indices are exist in the set, and their array values are `0`.

We should do `answer[0] -= 3`, since the number of `0`s in the quardtree is decreased from 4 to 1.
From the set, discard `(0, 4)`, `(0, 6)`, `(2, 4)`, `(2, 6)`, and insert `(0, 4)` into it.

* Result set: (0, 4)

### Conclusion
After looking at all quardtrees, you notice there is no more conquer, and no keys in the pair set.
Now the program ends all loops and returns the result.
</details>
