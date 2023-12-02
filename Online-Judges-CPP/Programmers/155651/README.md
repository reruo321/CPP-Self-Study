# [155651] Minimum Hotel Rooms
* Problem Link: https://school.programmers.co.kr/learn/courses/30/lessons/155651

Present the solution to find the minimum number of hotel rooms required for book scheduling by **proving it mathematically**.
  
## Solution
<details>
  <summary><b>Spoilers</b></summary>
This kind of problem is called <b>"Interval Partitioning"</b>, and its solution is <b>Greedy Algorithm</b>. Sort all intervals (booking) first, and then schedule them.

Answer: The sort algorithm should sort intervals by start time.

### Algorithm
Apply specific sorting algorithm to all intervals, and schedule them like FIFO; first booking, first scheduling.

1. (Sort all intervals with specific algorithm)
2. Read the start time & end time of the first booking.
3. Examine the 1st, 2nd, 3rd, ... N-th room schedule.
  
  a. If a K-th room schedule can accept the booking, put it into the schedule.

  b. If not, examine the (K+1)-th, the next room schedule.

3. The total number of room schedules is the answer.

### Counter-Examples
For greedy algorithm, we can think four ways to sort intervals:

1. ★ Earliest start time
2. Earliest finish time
3. Fewest conflicts
4. Shortest interval
   
The answer is the first. For other sorting methods, the upper schedule is a counter-example.
The lower one is the right answer.
#### No Sort
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/cce337f5-3340-4aa1-9419-7d6b6151ecac)

#### 2. Earliest Finish Time
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/15d9add3-822b-4da1-b297-5322a1386e13)

#### 3. Fewest Conflicts
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/036b823f-bcdb-49e5-b848-94931c4414fa)

##### Algorithm Explanation
In the context of "fewest conflicts" sorting in interval partitioning, the term "conflict" refers to the overlapping of intervals.
When conflicts exist, the approach would prioritize scheduling intervals first that have fewer conflicts with other intervals.

The algorithm involves precomputing the number of conflicts for each interval and sorting them based on this count. Therefore, we only need to perform this computation once at the beginning before applying the greedy algorithm.

Intervals from the upper sides  figure above 

#### 4. Shortest Interval
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/224e38ae-6bb0-4b89-8c7a-d23e0db3b358)

### Real Solution: Earliest Start Time
Sort all bookings by its start time in ascending order. It will prevent the counter-examples.

#### Proof
##### Claim:
##### Proof:




</details>
