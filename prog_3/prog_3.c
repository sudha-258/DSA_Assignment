#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create_new_node(int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void reverse_traverse(struct node *head){
    if(head == NULL){
        return;
    }
    reverse_traverse(head->next);
    printf("%d\n", head->data);
}

int main(){
    struct node* head = NULL;
    struct node* temp = NULL;
    char again = 'Y';
    int value;

    while (again == 'Y' || again == 'y'){
        printf("Enter the node for the linked list: ");
        scanf("%d", &value);

        struct node* new_node = create_new_node(value);

        if (head == NULL){
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = new_node;
        }

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &again);   // space avoids newline issue
    }

    printf("\nReverse Traversal of Linked List:\n");
    reverse_traverse(head);

    return 0;
}