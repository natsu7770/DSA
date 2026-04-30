#include <stdio.h>
#include <stdlib.h>

// Define the Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Helper function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        Node* newNode = createNode(val);

        if (head == NULL) {
            // First node becomes both head and tail
            head = tail = newNode;
        } else {
            // Link the current tail's next to the new node
            tail->next = newNode;
            // Link the new node's prev back to the current tail
            newNode->prev = tail;
            // Move the tail pointer to the new node
            tail = newNode;
        }
    }

    // Forward Traversal
    Node* temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, temp->next ? " " : "");
        temp = temp->next;
    }
    printf("\n");

    // Clean up memory
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}  