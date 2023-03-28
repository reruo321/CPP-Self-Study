# [17680] Cache

What data structure will you use for implementing LRU cache in C++?

## Naive Solution
The naive and the easiest solution to think will be...

<details>
<summary>Spoilers</summary>
Vector.

Using others such as list would be also fine.
</details>

## Using Two Data Structures

<details>
<summary>Spoilers</summary>
According to Geeksforgeeks, we can also use list and map.

    list<string> li;
    map<string, list<string>::iterator> ma;

</details>
