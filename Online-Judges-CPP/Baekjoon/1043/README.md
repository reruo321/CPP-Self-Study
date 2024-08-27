# Lie
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Use the union-find algorithm to find all mates that can (in)directly know the truth.

### Note
* You should not use `vector<vector<int>>` to store whole party members, or you'll meet a time-out failure! Instead, follow these steps:

1. Define a `vector<int>` to store the party information.
2. "Union" all party members in an `i`-th party.
3. Store just one member's number as an `i`-th element of the vector.
4. Later you can check the root of all party members, by "find"ing the root of the member in the vector. If the root is connected with any members who can know the truth, then Jimin should avoid lying in that party.

</details>
