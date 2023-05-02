# Sort
## Header
    #include <algorithm>
## *sort()*
    template <class RandomAccessIterator> void sort (RandomAccessIterator first, RandomAccessIterator last);
    template <class RandomAccessIterator, class Compare> void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);

### Example

    // ASC: Ascending order, DESC: Descending order

    // Helps sort() to sort elements in ASC.
    bool compare(const int &a, const int &b){
        return a < b;
    }
    
    .
    .
    .
    
    vector<int> vec1 = {5, 9, 3, 4, 7, 1, 2, 0, 8, 6};
    vector<vector<int>> vec_sort(5, vector<int>(vec1));


    sort(vec_sort.at(0).begin(), vec_sort.at(0).begin()+5);  // Sort up to fifth element (ASC)
    sort(vec_sort.at(1).begin(), vec_sort.at(1).end());     // Sort (ASC)
    sort(vec_sort.at(2).begin(), vec_sort.at(2).end(), compare);    // Sort (compare, ASC)
    sort(vec_sort.at(3).begin(), vec_sort.at(3).end(), less<int>());    // Sort (ASC)
    sort(vec_sort.at(4).begin(), vec_sort.at(4).end(), greater<int>());     // Sort (DESC)

    /*
        Original Vector: 5 9 3 4 7 1 2 0 8 6
        Sorted Vector 1: 3 4 5 7 9 1 2 0 8 6
        Sorted Vector 2: 0 1 2 3 4 5 6 7 8 9
        Sorted Vector 3: 0 1 2 3 4 5 6 7 8 9
        Sorted Vector 4: 0 1 2 3 4 5 6 7 8 9
        Sorted Vector 5: 9 8 7 6 5 4 3 2 1 0
    */
