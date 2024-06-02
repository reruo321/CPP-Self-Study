# Sorting Algorithms in C++
Time Complexity:
1. O(n^2)
  * Insertion Sort
  * Bubble Sort
  * Selection Sort
2. O(nlog(n))
  * Quick Sort
  * Merge Sort
  * Heap Sort
  * Introspective Sort

## A. O(n^2)
### 1. Insertion Sort
Pick an element and put it into the adaquate place.

### 2. Bubble Sort
Exchange two elements. Loop from the start element to the last element, until there's no more exchanging happens.

### 3. Selection Sort
Select two elements, and if they need to be changed, change them.

## B. O(nlog(n))
### 1. Quick Sort
Use pivot & divide-and-conquer. Select a pivot of a subset by choosing one of these options:

A. Select the first element of the subset.
B. Select the last element of the subset.
C. Select the median of the subset. For example, get a pivot by getting the median of 3 random elements from the full set.

#### Steps
1. Select a pivot of an entire set. (Let its size N.) I'll select the last element, (N-1)th, of a set as a `pivot`.
2. Define a pivot index `pidx`. It is used to put the `pivot` after finishing to sort all other numbers in the set. I'll assign `pidx` = 0.
3. A number X <= `pivot` should be left of the pivot, and otherwise should be right of the pivot. (Mechanism: Run a loop from the 0th element to the (N-2)th element. If i-th element X <= `pivot`, swap X and set\[pidx\], and increase `pidx` by 1.)
4. After the loop, swap set\[pidx\] and set\[N-1\].
5. Return `pidx` to divide the set into 0th ~ (`pidx`-1)th, and (`pidx`+1)th ~ (N-1)th elements.
6. Run the quick sort again to two subsets. Repeat these until `start` >= `end`, where `start` and `end` are the start/end indices of a set.

### 2. Merge Sort
Use divide-and-conquer. Divide an input set into half until all subset have 1 element. Conquer two subsets with two pointers; Set a pointer for the first element of subset 1, and for the first element of subset 2. Compare two numbers, push less or the same element to a new bigger set, move the pointer (which was pointing to the pushed element) to the right, and compare two numbers again.

### 3. Heap Sort
**Heap** is a tree-based data structure.

### 4. Introspective Sort
Hybrid sorting altorithm that is used in the Standard C++ Library. It combines the strengths of quick sort, heap sort, and insertion sort.
It takes quick sort first, and later changes its sort algorithm based on the data size.

1. Quick Sort: Starting algorithm
2. Heap Sort: When the recursion depth exceeds a certain threshold (commonly log2(n))
3. Insertion Sort: For small partitions or when the size of the data becomes small enough
