#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to calculate the length of a linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point based on node values
void findIntersection(struct Node* head1, struct Node* head2, int n, int m) {
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Calculate difference in lengths
    int diff = abs(n - m);

    // Advance the pointer of the longer list by 'diff' nodes
    if (n > m) {
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }

    // Traverse both lists simultaneously and compare data
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

// Helper to build list from input
struct Node* buildList(int n) {
    if (n <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    int n, m;

    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = buildList(n);

    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = buildList(m);

    findIntersection(list1, list2, n, m);

    return 0;
}