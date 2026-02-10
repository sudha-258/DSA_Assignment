# Doubly Linked List: Insertion and Deletion

This project demonstrates the implementation of a Doubly Linked List (DLL) in C. Unlike a singly linked list, each node in a DLL maintains references to both the next and the previous nodes, allowing for bidirectional traversal.

---

## (a) Data Structure Definition

The structure for a Doubly Linked List node includes an additional pointer compared to a standard linked list:

* **`int data`**: Stores the integer value.
* **`struct node* next`**: Pointer to the succeeding node.
* **`struct node* prev`**: Pointer to the preceding node.



```c
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;
```
## (b) Function Descriptions
1. create_new_node(int value): Allocates memory for a new node and initializes its pointers.
2. insert_at(struct node* given_node, int value): Inserts a new node immediately after a specific existing node.
3. delete_node(struct node** head, struct node* del): Removes a specific node from the list and frees its memory.


## (c) Main Method 
The main() function demonstrates the full lifecycle of a Doubly Linked List:
1. Manual Setup: It creates five nodes and manually establishes the bidirectional links (forward and backward) to show the underlying structure.
2. Display: Uses a display() function to print the list with <-> symbols, representing the two-way connection.
3. Verification: After each operation, the list is printed to verify that the next and prev links remain intact.

## (d) Sample Output
```c
Initial Doubly Linked List:
1 <-> 2 <-> 3 <-> 4 <-> 5 <-> NULL

After inserting 15 after 2:
1 <-> 2 <-> 15 <-> 3 <-> 4 <-> 5 <-> NULL

After deleting node with data 2:
1 <-> 15 <-> 3 <-> 4 <-> 5 <-> NULL
```




