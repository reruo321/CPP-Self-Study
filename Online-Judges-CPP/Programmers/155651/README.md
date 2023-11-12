# [155651] Minimum Hotel Rooms
* Problem Link: [https://school.programmers.co.kr/learn/courses/30/lessons/155651]

Present the solution to find the minimum number of hotel rooms required for book scheduling by **proving it mathematically**.

Suppose that:
1. `book_time` is the 2D vector that shows the list of hotel booking times. Let's say its size is `N`.
2. A booking time `book_time[i]` is given like this: \["HH:MM", "HH:MM"\], meaning \[`BOOKING_START_TIME`, `BOOKING_END_TIME`\].
3. Time format: `string` ("HH:MM"), from "00:00" to "23:59"
4. `BOOKING_START_TIME` < `BOOKING_END_TIME`.
5. No booking after midnight.

## My Trial and Error
**※ Warning: My approach was not correct. See below for the correct one. ※**

<details>
  <summary><b>Spoilers</b></summary>
  
    (Pseudo Code)
    
    answer = 1;
    bool arr[1000][24*60];
  
    for(i=0; i<N; ++i){
        let start = convert_to_minute(book_time[i][0]);
        let end = convert_to_minute(book_time[i][1]) + 10;
        if. end >= 24*60:
            end = 24*60;
        
        let is_filled = true;
        for(j=0; j<answer; ++j){
            for(k=start; k<end; ++k){
                is_filled = true;
                if. arr[j][k] == false: {
                    is_filled = false;
                    break;
                }
                if. is_filled == true:
                break;
            }
        }
        if. is_filled == false:
            ++answer;
        
        for(j=start; j<end; ++j){
            arr[answer-1][j] = true;
        }
    }
                            
    return answer;
</details>

### Counter-examples
  
## Solution
<details>
  <summary><b>Spoilers</b></summary>
  This kind of problem is called <b>"Interval Partitioning"</b>, and its solution is <b>Greedy Algorithm</b>.

There is one thing to add to my trial: we should sort all `book_time`s by its `BOOKING_START_TIME`, in ascending order. It will prevent the counter-examples.
  
### Proof for Greedy Algorithm
How can we prove that greedy algorithm for interval partitioning is optimal?
</details>
