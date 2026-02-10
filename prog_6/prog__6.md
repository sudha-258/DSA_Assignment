# Binary Heap Implementation: Min-Heap and Max-Heap

This program demonstrates how to transform an unsorted array into both a **Max-Heap** and a **Min-Heap** using the "heapify" process.

---

## (a) Data Structure Definition

While heaps are logically represented as **Complete Binary Trees**, they are physically implemented using a **Linear Array** for space efficiency. 

* **Root Element**: Always stored at `index 0`.
* **Parent-Child Mapping**: For any element at index $i$:
    * **Left Child**: $2i + 1$
    * **Right Child**: $2i + 2$
    * **Parent**: $\lfloor (i-1)/2 \rfloor$



---

## (b) Function Descriptions

### 1. `max_heap` and `min_heap` (Heapify)
* **Purpose**: These are recursive "sift-down" functions that maintain the heap property at a specific subtree.
* **Logic (Max-Heap)**: Compares a parent node with its children. If a child is larger, it swaps with the parent and continues heapifying down the tree.
* **Logic (Min-Heap)**: Same as above, but ensures the parent is always the smallest value among its children.

### 2. `build_max_heap` and `build_min_heap`
* **Purpose**: Converts an arbitrary array into a valid heap.
* **Algorithm**: It starts from the last non-leaf node (at index $n/2 - 1$) and works backward to the root. This ensures that when a node is heapified, the subtrees below it are already valid heaps.



### 3. `swap(int *x, int *y)`
* **Purpose**: A utility function that exchanges the values of two memory locations using a temporary variable.

---

## (c) Main Method Organization

The `main()` function follows a structured workflow:

1.  **Input Collection**: Prompts the user for the size of the array and the individual elements.
2.  **Array Duplication**: To demonstrate both heap types from the same source data, the original array is copied into `max_heap_arr` and `min_heap_arr`.
3.  **Heap Construction**: 
    * Calls `build_max_heap()` to organize the data such that the largest element is at the root.
    * Calls `build_min_heap()` to organize the data such that the smallest element is at the root.
4.  **Display**: Iterates through the resulting arrays to show the breadth-first (level-order) representation of the heaps.

---

## (d) Sample Output

```text
Enter the size of the array: 5
Enter the elements of array: 10
Enter the elements of array: 20
Enter the elements of array: 5
Enter the elements of array: 30
Enter the elements of array: 15

Max Heap: 30 20 5 10 15 
Min Heap: 5 15 10 30 20

