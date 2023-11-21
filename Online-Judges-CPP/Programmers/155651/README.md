# [155651] Minimum Hotel Rooms
* Problem Link: https://school.programmers.co.kr/learn/courses/30/lessons/155651

Present the solution to find the minimum number of hotel rooms required for book scheduling by **proving it mathematically**.
  
## Solution
<details>
  <summary><b>Spoilers</b></summary>
This kind of problem is called <b>"Interval Partitioning"</b>, and its solution is <b>Greedy Algorithm</b>. Sort all intervals (booking) first, and then schedule them.

### Basic Algorithm
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

#### 3. Fewest Conflicts

#### 4. Shortest Interval
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/224e38ae-6bb0-4b89-8c7a-d23e0db3b358)

### Real Solution: Earliest Start Time
Sort all bookings by its start time in ascending order. It will prevent the counter-examples.

#### Proof
##### Claim:
##### Proof:




</details>
