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
Change two elements.

### 3. Selection Sort
Select two elements, and if they need to be changed, change them.

## B. O(nlog(n))
### 1. Quick Sort
Use pivot & divide-and-conquer.

#### Pivot Selection
1. The first element in the set
2. The last element in the set
3. The median of multiple elements

### 2. Merge Sort
Use divide-and-conquer. Divide an input set into half until all subset have 1 element.

### 3. Heap Sort
**Heap** is a tree-based data structure.

### 4. Introspective Sort
Hybrid sorting altorithm that is used in the Standard C++ Library. It combines the strengths of quick sort, heap sort, and insertion sort.
It takes quick sort first, and later changes its sort algorithm based on the data size.

1. Quick Sort
2. Heap Sort
3. Insertion Sort
