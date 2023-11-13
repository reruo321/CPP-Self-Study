# [155651] Minimum Hotel Rooms
* Problem Link: https://school.programmers.co.kr/learn/courses/30/lessons/155651

Present the solution to find the minimum number of hotel rooms required for book scheduling by **proving it mathematically**.
  
## Solution
<details>
  <summary><b>Spoilers</b></summary>
  This kind of problem is called <b>"Interval Partitioning"</b>, and its solution is <b>Greedy Algorithm</b>.

### Wrong Approach
**※ Warning: This approach is not correct. See below for the correct one. ※**

Without sorting, just applied a FIFO concept; first booking, first scheduling.

1. Read the start time & end time of the first booking.
2. Examine the 1st, 2nd, 3rd, ... N-th room schedule.
  
  a. If a room schedule can accept the booking, put it into the schedule.

  b. If not, examine the next room schedule.

3. The total number of room schedules will be the answer.

### Counter-Examples
We will sort the bookings, and then schedule them one by one.
For each sorting method, the upper schedule is a counter-example.
The lower one is the right answer, which sorts the bookings by start time.
#### No Sort
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/cce337f5-3340-4aa1-9419-7d6b6151ecac)

#### Shortest First
![image](https://github.com/reruo321/CPP-Self-Study/assets/48712088/224e38ae-6bb0-4b89-8c7a-d23e0db3b358)

### Real Solution
There is one thing to add to my approach: sort all bookings by its start time in ascending order. It will prevent the counter-examples.

How can we prove that greedy algorithm for interval partitioning is optimal?
</details>
