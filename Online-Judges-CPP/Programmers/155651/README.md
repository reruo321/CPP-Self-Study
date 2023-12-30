# [155651] Minimum Hotel Rooms
* Problem Link: https://school.programmers.co.kr/learn/courses/30/lessons/155651

Present the solution to find the minimum number of hotel rooms required for book scheduling by **proving it mathematically**.
  
## Solution
<details>
  <summary><b>Spoilers</b></summary>
This kind of problem is called <b>"Interval Partitioning"</b>, and its solution uses <b>Greedy Algorithm</b>.
  
Using the greedy algorithm, sort all intervals (bookings) by start time in ascending order, and schedule them.

### Basic Algorithm
Apply specific sorting algorithm to all intervals, and schedule them.

1. (Sort all intervals with specific algorithm)
2. Read the start time & end time of the first booking.
3. Examine the 1st, 2nd, 3rd, ... N-th room schedule.
  
  a. If a K-th room schedule can accept the booking, put it into the schedule.

  b. If not, examine the (K+1)-th, the next room schedule.

3. The total number of room schedules is the answer.

### Greedy Algorithms
We can think four greedy algorithm approaches to sort intervals:

1. ★ Earliest start time
2. Earliest finish time
3. Fewest conflicts
4. Shortest interval
   
※ The answer is the first one. I uploaded two figures per greedy algorithm which is not an answer. The upper schedule figure is a counter-example, and the lower one is the right answer sorting by start time.

### Not Optimal Algorithms
While certain approaches may incorporate greedy algorithms, it's essential to recognize that not all of them guarantee optimality. The proof lies in finding counterexamples, and just one counterexample per algorithm is sufficient to challenge their optimality.

#### No Sort
##### Counterexample
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/cce337f5-3340-4aa1-9419-7d6b6151ecac)

#### 2. Earliest Finish Time
##### Counterexample
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/15d9add3-822b-4da1-b297-5322a1386e13)

#### 3. Fewest Conflicts
##### Counterexample
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/036b823f-bcdb-49e5-b848-94931c4414fa)

##### Algorithm Explanation
In the context of "fewest conflicts" sorting in interval partitioning, the term "conflict" refers to the overlapping of intervals.
When conflicts exist, the approach would prioritize scheduling intervals first that have fewer conflicts with other intervals.

The algorithm involves precomputing the number of conflicts for each interval and sorting them based on this count. Therefore, we only need to perform this computation once at the beginning before applying the greedy algorithm.

![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/45f17714-6ad1-45d2-98db-54c26e95812f)

Let's see this figure again. Each interval has start time and end time like this:

* A: [0, 4]
* B: [6, 8]
* C: [4, 10]
* D: [0, 5]

I said "conflict" is the overlap between two intervals. Let's count them!

* A: 1 (Conflict with D)
* B: 1 (Conflict with C)
* C: 2 (Conflict with B, D)
* D: 2 (Conflict with A, C)

Therefore, the order of the intervals will be A-B-C-D, B-A-D-C, or anything else. The order between "A and B", or "C and D" does not matter at all.

**Proof for Order of the Intervals**

### 4. Shortest Interval
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/224e38ae-6bb0-4b89-8c7a-d23e0db3b358)

### Solution: 1. Earliest Start Time
Greedy algorithm that sorts intervals by start time in ascending order is optimal in interval partitioning.
These two theorems support the optimality of the algorithm.

1. Locally optimal choice by a greedy algorithm leads to a globally optimal solution.
2. Greedy algorithm that sorts intervals by start time is optimal in interval partitioning.

#### Theorem 1:
Locally optimal choice by a greedy algorithm leads to a globally optimal solution.

##### Definition:

Let f(x) be a greedy algorithm that is used in a problem, where x can be either an element or a set. Let S be the set of elements that f(x) should be applied.

- When $n=1$, the locally optimal choice in the sorted set $*S'*$ is the globally optimal choice.
- Assume that for k elements, the statement holds for the sorted set S’:
    
    f(G_k) = f(L_1)+f(L_2)+…+f(L_k).
    
- f(G_k+1) = f(L_1)+f(L_2)+…+f(L_k)+f(L_k+1)

#### Theorem 2: Greedy Algorithm for Interval Partitioning
Greedy algorithm that sorts intervals by start time is optimal in interval partitioning.

##### **Definition:**
Let the greedy algorithm that sorts lectures by start time and assigns them to classrooms be $G$.

##### **Assumption:**
Suppose there exists an optimal solution $O$ that does not follow the greedy algorithm of sorting lectures by start time. Let the first lecture that is scheduled differently in $G$ and $O$ be $L$. Since $G$ is a greedy algorithm, it always makes the locally optimal choice. Therefore, the lecture $L$ scheduled by $G$ at this point is the best possible choice among all lectures at that time. In $O$, the lecture $L$ is scheduled differently. This means that $O$ has chosen a different lecture at this point. Let this lecture be $M$. There must be a difference in scheduling at $L$ and $M$.

##### **Case 1: No Conflicts Introduced by $L$ and $M$ with Other Lectures in $G$**:
The cases that $L$ and $M$ do not introduce any conflicts with other lectures in $G$. This means neither of them affect other lectures, no matter which schedules they belong to.

Also, whether $L$ and $M$ conflict with each other or not does not matter. Even if they do, the only conflict they can make is always the same thing; the conflict with $L$ and $M$. They still do not make any conflicts with other lectures at all. Therefore, $L$ and $M$ in the Case 1 has no effect on the number of schedules and the optimality of $G$ and $O$.

##### **Case 2: Conflicts Introduced by $L$ and $M$ with Other Lectures in $G$:**
The cases that $L$ and $M$ introduce conflicts with other lectures in $G$.

There must be some conflict or overlap introduced by $O$ that $G$ avoided, or resolved by $O$ that $G$ introduced. These conflicts have the potential to increase/decrease the number of classrooms needed in $O$, as it may introduce/resolve overlaps that were not/were present in $G$. The specific impact on the total number of classrooms will depend on the subsequent scheduling decisions and how the conflicts are resolved in the course of the algorithm.

We can use the “exchange argument” technique here, a common approach in algorithm analysis to prove the optimality of greedy algorithms. The purpose of exchanging the positions of lectures $L$ and $M$ in $O$ is to create a new algorithm $O’$, without affecting the schedule of other lectures. If there is a $O'$ with fewer/more classrooms than $O$, it becomes a contradiction/support of the assumption that $O$ is optimal. Especially, when $O’$ have the same scheduling as $G$, it also reinforces/contradicts the theorem that $G$ is optimal.

##### **Exchange Argument Example:**

Let’s look at the example. There are four lectures including $L$ and $M$.

$A: [0, 4]$

$B: [1, 5]$

$L: [4, 8]$

$M: [5, 7]$

The greedy algorithm $G$ schedules them in the order $A-B-L-M$. It makes $2$ classrooms: $A$ and $L$ are in $Classroom 1$, $B$ and $M$ are in $Classroom 2$.

Suppose that there’s an algorithm $O$ which is different from $G$ and schedules the lectures in the order $A-B-M-L$. It makes $3$ classrooms: $A$ and $M$ are in $Classroom 1$, $B$ is in $Classroom 2$, and $L$ is in $Classroom 3$.

Let’s apply the “exchange argument” here. Exchanging the order of $L$ and $M$ creates a new algorithm, $O’$. $O’$ schedules the lectures in the order $A-B-L-M$, matching the scheduling order of the greedy algorithm $G$. Note that, as $O$ has more classrooms than $O’$, the optimality of $O$ is worse than that of $O’$. Therefore, $O$ is not the optimal algorithm in interval partitioning. Moreover, the fact that $O’$ schedules the lectures in the same order as $G$ further demonstrates that $O$ is not more optimal than $G$.

Note that, as $O$ has more classrooms than $O'$, the optimality of $O$ is worse than that of $O'$. Therefore, $O$ is not the optimal algorithm in interval partitioning. Moreover, the fact that $O'$ schedules the lectures in the same order as $G$ further demonstrates that $O$ is not more optimal than $G$.

![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/b09d297a-2f7f-4abc-9a64-53c68eb05ac7)

##### **Contradiction:**

We can also assume many $O$ algorithms different from $G$ being optimal, exchange scheduling order of some two lectures $L$ and $M$, and find contradictions. We obtain $O’$ that has the same or fewer classrooms as $O$. This contradicts the assumption that there is an $O$ algorithm which is more optimal than $G$, because we found a solution with the same or fewer classrooms that is at least as good as $G$.

##### **Conclusion:**

The contradiction implies that our assumption of the existence of an optimal solution different from $G$ is false. Therefore, the greedy algorithm that sorts lectures by start time is optimal for the interval partitioning problem.

</details>
