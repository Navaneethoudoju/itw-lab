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

