# [1377] Bubble Sort

## Solution
<details>
<summary><b>SPOILERS</b></summary>
Find the number of times to run bubble sort.
If nothing changed in a sort, stop the program.

### Code Explanation
```
bool changed = false;
for (int i=1; i<=N+1; i++) {
    changed = false;
    for (int j=1; j<=N-i; j++) {
        if (A[j] > A[j+1]) {
            changed = true;
            swap(A[j], A[j+1]);
        }
    }
    if (changed == false) {
        cout << i << '\n';
        break;
    }
}
```
* `N`: The size of the array `A`.
* `changed`: The flag to check if any changes happened in a sort.
* `i`: The iterative number to tell the number of times of the bubble sort so far.
* `j`: The iterative number to tell the index of an element in the array `A`.

</details>
