# Tetromino
## Solution 1

![baek14500](https://user-images.githubusercontent.com/48712088/197559094-a88a8193-d865-49b2-8af4-08e9e18b7f98.jpg)

Since there were so many many tetris shapes (and their rotations) to check, I instead divided the problem into 1x4, 2x3, 3x2, and 4x1.

Especially for 2x3 and 3x2 cases, I found the maximum tetris-sum from each of them by (*sum_of_six_blocks* - MIN(*sum_of_two_blocks*)).
Do not forget some exceptions that has no tetris shape!

## Solution
Use DFS to make most type of tetris blocks. Almost types of tetromino except one resembling "T" can be make by 4-level DFS.
