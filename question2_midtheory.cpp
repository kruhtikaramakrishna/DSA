#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* reverseSegment(struct Node* head, int m, int n) {
    if (!head) return NULL;
    
    struct Node* prev = NULL;
    struct Node* curr = head;
    
    while (m > 1) {
        prev = curr;
        curr = curr->next;
        m--; n--;
    }
    
    struct Node* con = prev;
    struct Node* tail = curr;
    struct Node* third = NULL;
    
    while (n > 0) {
        third = curr->next;
        curr->next = prev;
        prev = curr;
        curr = third;
        n--;
    }
    
    if (con != NULL) con->next = prev;
    else head = prev;
    
    tail->next = curr;
    return head;
}

int main() {
    int m, n;
    struct Node* head = createNode(101);
    head->next = createNode(102);
    head->next->next = createNode(103);
    head->next->next->next = createNode(104);
    head->next->next->next->next = createNode(105);
    head->next->next->next->next->next = createNode(106);
    head->next->next->next->next->next->next = createNode(107);

    printf("Original Playlist:\n");
    printList(head);

    printf("Enter m and n: ");
    scanf("%d %d", &m, &n);

    head = reverseSegment(head, m, n);
    
    printf("Modified Playlist:\n");
    printList(head);
    return 0;
}


