#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
    struct ListNode *prev; 
};

void swap(struct ListNode *a, struct ListNode *b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

struct ListNode* partition(struct ListNode *low, struct ListNode *high) {
    int pivot = high->val;
    struct ListNode *i = low->prev;
    for (struct ListNode *j = low; j != high; j = j->next) {
        if (j->val <= pivot) {
            i = (i == NULL) ? low : i->next;
            swap(i, j);
        }
    }
    i = (i == NULL) ? low : i->next;
    swap(i, high);
    return i;
}

void quickSort(struct ListNode *low, struct ListNode *high) {
    if (high != NULL && low != high && low != high->next) {
        struct ListNode *p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

struct ListNode *getLastNode(struct ListNode *head) {
    while (head != NULL && head->next != NULL)
        head = head->next;
    return head;
}

void printList(struct ListNode *node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

struct ListNode* newNode(int data) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = data;
    temp->next = NULL;
    return temp;
}

int main() {
    struct ListNode *a = newNode(10);
    a->next = newNode(7);
    a->next->next = newNode(8);
    a->next->next->next = newNode(9);
    a->next->next->next->next = newNode(1);
    a->next->next->next->next->next = newNode(5);

    struct ListNode *last = getLastNode(a);
    quickSort(a, last);

    printf("Sorted Linked List is: \n");
    printList(a);

    return 0;
}