# [86491] The Smallest Rectangle
* Problem Link: https://school.programmers.co.kr/learn/courses/30/lessons/86491

Present the solution to find the smallest wallet area by **proving it mathematically**.

## Solution
<details>
<summary><b>SPOILERS</b></summary>
  
![rec](https://github.com/reruo321/CPP-Self-Study/assets/48712088/58042887-fbbb-4d0c-9c86-78c00a449d28)

Express a rectangle Rm like Rm = (Wm, Hm), where Wm is the width and Hm is the height. Let the bigger value between Hm and Wm is am, and the smaller one is bm. Let A = {a1, a2, ... an}, B = {b1, b2, ... bn}, where n is the number of rectangles.

Then the answer is ax * by, where ax is the biggest value in A, and by is the biggest value in B.

### Proof
Suppose that K = Wk is the biggest among all width and height values. 

Suppose that there are set A and set B.

Let A = {a1, a2, ... an}, B = {b1, b2, ... bn} where n is the number of rectangles.

Let ap and bq are having a vertical relationship for every 1 <= p, q <= n.

1. Wk >= Hk. Let Wk ∈ A, then Hk ∈ B.
2. K is always the biggest value in A.
3. Every element in B must be the smaller value in a rectangle.
   
   i. Suppose, for the sake of contradiction, Proposition 3 is false. Let B has some bigger values in the rectangles.
   
   ii. Suppose that R1 = (1000, 1), R2 = (500, 3), R3 = (100, 10).
   
   iii. Then K = 1000.
   
   iv. Let W3 = 100 is in B. Then A = {1000, 500, 10}, B = {1, 3, 100}.
   
   v. The situation becomes a counterexample. The answer from Proposition iv is 1000 * 100 = 100000, but the real answer is 1000 * 10 = 10000 when A = {1000, 500, 100}, B = {1, 3, 10}.
   
   vi. Therefore, B does not contain any bigger value in every rectangle.

5. Let ax is the biggest value in A, and by is the biggest value in B.
6. K = ax, and we can also find by with a comparing algorithm.
7. Since ax and by are having the vertical relationship, we can conclude that the answer is ax * by.

</details>
