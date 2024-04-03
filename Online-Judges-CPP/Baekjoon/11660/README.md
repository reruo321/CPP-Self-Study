# Finding Prefix Sum
Prefix sum (구간 합) is a sum of specific range.

For example, suppose that there's a set of numbers like A1, A2, ... A(n-1), An.
And we need to find the sum of Ai, A(i+1), ..., Aj for n times, where i and j vary.

1. If we add elements in specific range every time, the time complexity is O(n^2).
2. How about using **prefix sum** here? After the preprocessing on a S set, where S is a prefix sum, we just need to calculate Sj - S(i-1).
