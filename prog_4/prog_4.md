# Doubly Linked List Implementation
# Objective:
     The objective of this program is to implement a doubly linked list in C, which allows:
* Traversing nodes in both forward and backward directions.
* Inserting a new node after a given node.
* Deleting a node by value.
* Dynamically creating nodes using user input.

  ### Defining Data-Structure:
  ```c
  struct Node {
    int data;          
    struct Node* next;  
    struct Node* prev; 
};
```
   

