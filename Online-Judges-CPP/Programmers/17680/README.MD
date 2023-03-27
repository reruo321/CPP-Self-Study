# [17680] Cache

What data structure will you use for implementing LRU cache in C++?

## Naive Solution
The naive and the easiest solution to think will be...

<details>
<summary>Spoilers</summary>
Vector.
I worried about the fact that deleting elements in the middle of the vector is inefficient.
Fortunately, it anyway solves all test cases in the problem.

Using list would have been also fine.
</details>
