#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to count the number of nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;           // Increment counter for each node
        current = current->next; // Move to the next node
    }
    
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL, *tail = NULL;

    // Create the Linked List
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Call the count function and print the result
    int totalNodes = countNodes(head);
    printf("%d\n", totalNodes);

    // Memory Cleanup
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}