# List
**List**: Sufficient for inserting/deleting elements, even if they are not on the edge.
(Some other containers such as vector would not be good choices to do them.)

## Iterator
Make its iterator to find, erase, or go to a loop.

    list<int> mylist;
    list<int>::iterator it;

## **erase()**
**WARNING!** You should assign the iterator again when you are erasing something, or it will point to erased element.
(Do not need to take care of it while using vector though.)

    it = mylist.erase(it);  // Should do like this!
    mylist.erase(it);   // In this line "it" will point to ERASED element...

# Forward List
* Like **singly-linked list**
* Only goes forward (`list`: goes both ways)
* More efficient than `list`.
