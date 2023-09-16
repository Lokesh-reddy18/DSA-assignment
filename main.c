#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to push a node onto the stack
void push(struct Node** stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a node from the stack
int pop(struct Node** stack) {
    if (*stack == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = *stack;
    *stack = (*stack)->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to reverse a linked list using a stack
void reverseLinkedList(struct Node** head) {
    struct Node* stack = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        push(&stack, current->data);
        current = current->next;
    }

    current = *head;
    while (current != NULL) {
        current->data = pop(&stack);
        current = current->next;
    }
}

// Function to print a linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample linked list
    struct Node* head = NULL;
    for (int i = 1; i <= 5; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    printf("Original Linked List: ");
    printList(head);

    // Reverse the linked list using a stack
    reverseLinkedList(&head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
