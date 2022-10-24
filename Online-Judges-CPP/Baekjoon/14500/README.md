![baek14500](https://user-images.githubusercontent.com/48712088/197559094-a88a8193-d865-49b2-8af4-08e9e18b7f98.jpg)

Since there are so many many tetris shapes (and their rotations) to check, I instead divide the problem into 4x1, 3x2, 2x3, and 1x4.

Especially for 3x2 and 2x3 cases, I found the maximum tetris from each of them by MAX(sum_of_six_blocks - MIN(sum_of_two_blocks)).
Do not forget some exceptions that has no tetris shape!
