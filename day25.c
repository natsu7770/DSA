#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to count occurrences of a key in the list
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}

// Helper function to create and link nodes from input
struct Node* buildList(int n) {
    if (n <= 0) return NULL;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    int n, key;

    // Read number of nodes
    if (scanf("%d", &n) != 1) return 0;

    // Build the list
    struct Node* head = buildList(n);

    // Read the key to search for
    if (scanf("%d", &key) != 1) return 0;

    // Get count and print
    printf("%d\n", countOccurrences(head, key));

    // Memory Cleanup
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}