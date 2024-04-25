# Queue
**Queue**: FIFO

# Priority Queue
**Priority queue** automatically sorts the elements in the queue.
## Header
    #include <queue>
## Assignment
    // default comparison function is `less()`. **Top element is the greatest.**
    priority_queue<int> qu1;
    // greater() will make its top the least.
    priority_queue<int, vector<int>, greater<int>> qu2;
    // Sort with a custom comparator
    
