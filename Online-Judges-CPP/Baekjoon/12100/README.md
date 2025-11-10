# 2048 (Easy)
## Solution
<details>
<summary><b>SPOILERS</b></summary>
Create the board class (or struct) and its member variable or functions, following the instructions from the problem.

### Code Explanation
* `Board`: The class that expresses whole game.
* `GameCase`: The class that expresses a case that can happen while a user is playing the game, whose initial condition is given by inputs.
* `printGame`: The debugging function to track the information on game.
* `findMaxValue`: The function to find the maximum value in the game.
* `moveAndConquer`: The function to express the "move-and-conquer" control in the game, which combines two same blocks into one.
* `moveDIR`: The function to move all blocks to specific direction, `DIR`.
* `playGame`: The function to initialize the game, and check all cases possible in the game.

### Algorithm Explanation
1. Initialize the board game by getting inputs, and initializing `Board` and `GameCase`. Put the initial `GameCase` into the queue.
2. Check all cases by running all kinds of `moveDIR` for all board in the queue, and increase the level up to 5. From the start to the end of the game (where the level of the board is 5), find the maximum value inside the board.
</details>
