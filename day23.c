#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; // Stack-allocated dummy node
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes of the non-empty list
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next; // Return the actual head (after the dummy)
}

// Function to read input and build a list
struct Node* buildList(int count) {
    if (count <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < count; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
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
    int n, m;
    
    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = buildList(n);
    
    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = buildList(m);

    struct Node* mergedHead = mergeLists(list1, list2);
    printList(mergedHead);

    return 0;
}