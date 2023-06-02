#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
};

// Function to search for an element in the linked list
int search(struct Node* head, int key) {
    int position = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        if (current->value == key)
            return position;
        current = current->next;
        position++;
    }
    
    return -1;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int currentPosition = 0;
    
    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }
    
    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }
    
    newNode->prev = current;
    newNode->next = current->next;
    
    if (current->next != NULL)
        current->next->prev = newNode;
    
    current->next = newNode;
}

// Function to insert a node at the head of the linked list
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;

    while (current != NULL && current->value != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
}

// Function to print all elements in the linked list in reverse order
void printReverseLinkedList(struct Node* head) {
    struct Node* current = head;

    while (current->next != NULL) {
        current = current->next;
