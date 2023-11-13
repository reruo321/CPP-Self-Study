# [155651] Minimum Hotel Rooms
* Problem Link: https://school.programmers.co.kr/learn/courses/30/lessons/155651

Present the solution to find the minimum number of hotel rooms required for book scheduling by **proving it mathematically**.
  
## Solution
<details>
  <summary><b>Spoilers</b></summary>
  This kind of problem is called <b>"Interval Partitioning"</b>, and its solution is <b>Greedy Algorithm</b>.

### Wrong Solution
**※ Warning: My approach was not correct. See below for the correct one. ※**

Before the real solution, I want to show you my trial and error was not correct and had a counter-example.

I just applied a FIFO concept.

1. Read the start time & end time of the first booking.
2. Examine the 1st, 2nd, 3rd, ... N-th room schedule.
  
  a. If a room schedule can accept the booking, put it into the schedule.

  b. If not, examine the next room schedule.

3. The total number of room schedules will be the answer.

#### Counter-Example

### Real Solution
There is one thing to add to my approach: sort all bookings by its start time in ascending order. It will prevent the counter-examples.

How can we prove that greedy algorithm for interval partitioning is optimal?
</details>
