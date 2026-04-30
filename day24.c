#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to delete the first occurrence of a key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: The head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next; // Changed head
        free(temp);        // Free old head
        return head;
    }

    // Case 2: Search for the key to be deleted
    // Keep track of the previous node to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 3: If key was not present in the list
    if (temp == NULL) return head;

    // Unlink the node from the linked list
    prev->next = temp->next;

    free(temp); // Free the memory of the deleted node

    return head;
}

// Helper: build list from input
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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d%s", head->data, head->next ? " " : "");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, key;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* head = buildList(n);
    
    if (scanf("%d", &key) != 1) return 0;

    head = deleteKey(head, key);
    printList(head);

    return 0;
}