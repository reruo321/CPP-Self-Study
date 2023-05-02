# Complexity
## Time Complexity
Guide: [Guide 1](https://adrianmejia.com/how-to-find-time-complexity-of-an-algorithm-code-big-o-notation/)
, [Guide 2](https://adrianmejia.com/most-popular-algorithms-time-complexity-every-programmer-should-know-free-online-tutorial-course/#Mergesort)

![Complexities-Graph1](https://user-images.githubusercontent.com/48712088/222981233-a6b1c11a-8c49-4162-94ae-69380c8d3a08.png)

We can find time complexity of codes by counting performed opperations, by using **Big-O notation**.

* ***n***: input size
* ***O***: The worst-case scenario growth rate function

A simple, intuitive way to know the complexity of a function is just putting n=1, n=2, n=3, ... and so on.

### Examples
* **O(1)**(Constant): Primitive operations (+-×/%, bit shift, etc.), Average lookup/inserting/deleting in hash table (Worst is O(n).)
* **O(logn)**(Logarithmic): Binary search
* **O(n)**(Linear): Single loop
* **O(nlogn)**(Linearithmic): Merge sort, Quick sort, ...
* **O(n^2)**(Quadratic): Double loop, Bubble sort
* **O(n^c)**(Polynomial): c-loop
* **O(2^n)**(Exponential): Power set (finding all subsets on a set), Fibonacci
* **O(n!)**(Factorial): Permutation

### Notes
* The absolute value of a number does not matter in primitive operations. (Both "4+3" and "53837493+2838384" are O(1).)
* Since primitive operations have maximum-value limits, they can have constant time.
* One-line code ≠ O(1). For example, `sort(myvector.begin(), myvector.end());`.
* Use only dominant term in O notation, without coefficients. if f(n) = 3n^2+2n+1, O(g(n)) = O(n^2).

### Master Theorem
[**Master theorem**](https://en.m.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms)): Asymptotic analysis for recurrence relations of types. **T(n) = aT(n/b) + f(n)**
where *a*: No. of subproblems, *b*: the factor by which *n* is reduced, *f(n)*: the running time outside of the recursion.

The recurrences often satisfy one of three forms, which is determined by how the work to split/recombine the problem *f(n)* relates to the critical exponent ccrit. = logb(a).

For example, master theorem can be used to find the running time of binary search or merge sort.

## Auxiliary Space and Space Complexity
* **Auxiliary Space**: The extra space or temporary spave used by an algorithm
* **Space Complexity**: Auxiliary space + Space used by input
