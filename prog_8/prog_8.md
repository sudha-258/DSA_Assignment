# Sorting Algorithm Performance Comparison

This program generates a list of random integers and allows the user to compare the performance of four different sorting algorithms by tracking their comparison and swap counts.

---

## (a) Data Structure Definition

The program primarily uses a **Dynamic Array** (Variable Length Array in C) to store the integers.

* **`arr[size]`**: A standard integer array where `size` is defined by the user at runtime.
* **Global Counters**: 
    * `comparision_count`: Tracks how many times two elements are compared ($a > b$).
    * `swap_count`: Tracks how many times elements are moved or exchanged in memory.

---

## (b) Function Descriptions

The program implements four distinct sorting strategies:

| Algorithm | Type | Description |
| :--- | :--- | :--- |
| **Bubble Sort** | Exchange | Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. |
| **Selection Sort** | Selection | Divides the array into a sorted and unsorted part; it repeatedly finds the minimum element from the unsorted part and moves it to the beginning. |
| **Insertion Sort** | Insertion | Builds the final sorted array one item at a time by "inserting" an element into its correct position among previously sorted elements. |
| **Merge Sort** | Divide & Conquer | Recursively splits the array into halves, sorts them, and then merges them back together in order. |




---

## (c) Main Method Organization

The `main()` function is organized into a clear operational pipeline:

1.  **Generation Phase**: Uses `rand() % 1000 + 1` to populate the array with $N$ random numbers between 1 and 1000.
2.  **User Interaction**: Presents a menu for the user to select one of the four algorithms.
3.  **Execution Phase**: A `switch` statement calls the chosen sorting function.
4.  **Analytics Phase**: Displays the "Before" and "After" states of the array and prints the total number of operations (comparisons and swaps) performed.

---

## (d) Sample Output

```text
Enter the number of elements: 5
Random array of size: 5 
Array: 450 12 890 34 120 

Choose Sorting Algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter choice: 1

Before Sorting:
450 12 890 34 120 

After Sorting:
12 34 120 450 890 

Total Comparisons: 10
Total Swaps: 5

