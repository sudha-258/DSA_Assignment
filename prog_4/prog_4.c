#include <stdio.h>
#include <stdlib.h>

// Define doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert a new node after a node with given value
void insertAfterValue(struct Node* head, int afterValue, int newValue) {
    struct Node* temp = head;

    // Find the node with data = afterValue
    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found!\n", afterValue);
        return;
    }

    struct Node* newNode = createNode(newValue);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    printf("Inserted %d after %d\n", newValue, afterValue);
}

// Delete a node by value
void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;

    // Find the node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found!\n", value);
        return;
    }

    if (*head == temp) {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    printf("Deleted node with value %d\n", value);
}

// Display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, data;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("\nInitial List:\n");
    displayList(head);

    int afterValue, newValue;
    printf("\nEnter the value of node after which to insert: ");
    scanf("%d", &afterValue);
    printf("Enter the value to insert: ");
    scanf("%d", &newValue);

    insertAfterValue(head, afterValue, newValue);
    displayList(head);

    int delValue;
    printf("\nEnter the value of node to delete: ");
    scanf("%d", &delValue);

    deleteByValue(&head, delValue);
    displayList(head);

    return 0;
}
