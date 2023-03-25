# [12973] Remove Adjacent Duplicates

<details>
  <summary><b>SPOILERS</b></summary>


**USE STACK**.

Examine the string just once is sufficient.
Put a char into the stack, compare the top to the next char, and pop() if they are duplicated.

Do not try to erase or concatenate something on the string.
Loops and edits on `1,000,000` characters are really crazy.
It'll be waste of time even if you pick up some good containers such as list and rope...

</details>
