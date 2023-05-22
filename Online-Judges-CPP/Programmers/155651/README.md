# [155651] Minimum Hotel Rooms
Find the minimum number of hotel rooms required for book scheduling.

Suppose that:
1. `book_time` is the 2D vector that shows the list of hotel booking times. Let's say its size is `N`.
2. A booking time `book_time[i]` is given like this: \["HH:MM", "HH:MM"\], meaning \[`BOOKING_START_TIME`, `BOOKING_END_TIME`\].
3. Time format: `string` ("HH:MM"), from "00:00" to "23:59"
4. `BOOKING_START_TIME` < `BOOKING_END_TIME`.
5. No booking after midnight.

I was using somewhat silly algorithm for this and other similar problems, so I want to share one of good solutions.

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

## Solution
<details>
  <summary><b>Spoilers</b></summary>
  This kind of problem is called **"Interval Partitioning"**, and its solution is **Greedy Algorithm**.
  
  
</details>