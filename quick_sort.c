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


