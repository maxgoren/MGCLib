# MGCLib
A C++ Library of commonly used Data Structures and Algorithms.

## Sequential Containers
 - List - implements a Doubly Linked List
 - Stack - singly linked LIFO Stack
 - Queue - singly linked list FIFO Queue
 - Priority Queue - Binary Heap (Max Ordered) 

## Non Sequential Containers (Ordered)
All ordered, non-sequential containers are implemented from (Left Leaning) Red/Black Tree base class.
 - Set
 - Map

## Sorting Algorithms
The Library offers interfaces to:
- IntroSort(unstable sorting)
- MergeSort(stable sorting) algorithms.

The library contains heapsort and insertion sort as well, though they are intended as helpers for the aformentioned algorithms and are
not intended to be called directly (though they can be)

## Other Algorithms
- swap - swap two elements in an array
- downHeap - place an element in an array in heap order.
- find - binary search in a sorted array
- find_uns - linear search for unsorted collections
