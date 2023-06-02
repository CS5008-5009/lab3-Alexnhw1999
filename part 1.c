#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int value;
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
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = *head;
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
    
    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtHead(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
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
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    if (current != NULL && current->value == key) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->value != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Function to print all elements in the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int key, position, value;

    // Inserting initial elements
    insert
