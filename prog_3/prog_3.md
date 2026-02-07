# Implementation of reverse traversal algorithm in linked list
## Objective:
    The objective of this program is to implement reverse traversal algorithm in linked list</p
### Defining Data-Structures:
```c
struct node{
    int data;
    struct node* next;
};

```

**Explanation:**
* `struct node`: is a structure defined for the node of linked list
* `int data`: It stores the data of a node
* `struct node *next`: It stores the pointer to the next node 

### Functions
* `main()`: The main fuction performs following operations:<br>
          - declares the head and temp variable<br>
          - Aceepts the input from the user<br>
          - Calls the `create_new_node` and `reverse_traverse` function<br>
          - Displays the reverse traversal fo the linked list <br>
* `void reverse_traverse(struct node *head){}`:
          This function traverses the linked list in revese order
* `struct node* create_new_node(int value){}`: This function creates a new node with a   
          value and assigns the next pointer to a new node or null
