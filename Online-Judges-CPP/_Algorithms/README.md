# Algorithms

## Finding Substring
Here are algorithms to find the index of substring in a string.

(n: the length of string, m: the length of pattern)

### Naive Algorithm
The simplest, using brute force approach. O(n-m+1).
### KMP
### Finite Automata
### Boyer Moore
#### The Bad Character Rule
#### The Good Suffix Rule
### Boyer-Moore-Horspool
1. Create the Bad Match Table with pattern.

    a. If the length of pattern is `m`, the value of an alphabet will be `m - index - 1`.
   
    b. From the 0th to the (m-2)th alphabets, get the value and write it on the table. If there is already the value for the same alphabet, just update.

    c. Take a look at the (m-1)th, the last alphabet of the pattern. If there is the value, leave it. Otherwise, the value is `m`.

    d. For all other unavailable alphabets (*) in the pattern, the values are `m`.

2. Put both the main string and the pattern on the 0th index.

3. Compare the m-1, m-2, ..., 0th alphabets of the pattern to those of the string in the same indices.

    a. If there is a mismatching index, stop and find the value of the string's alphabet from the table.

    - i. Shift the entire pattern to the right by `value`.

    - ii. Go back to step 3 and repeat.

    b. If all alphabets are matching, you find the answer!

    - i. To continue, shift the pattern to the right by `1`, and go back to step 3.
