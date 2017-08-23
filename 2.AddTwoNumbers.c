#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Definition for singly-linked list.
 */
struct _ListNode {
    int val;
    struct _ListNode *next;
};

typedef struct _ListNode ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* p1 = l1, * p2 = l2;
    ListNode* la = NULL, * pa = NULL;
    int carry = 0;
    while (p1 != NULL || p2 != NULL) {
        int sum = 0;
        if (p1 != NULL && p2 != NULL) {
            sum = p1->val + p2->val;
        } else if (p1 != NULL) {
            sum = p1->val;
        } else {
            sum = p2->val;
        }

        ListNode* node = malloc(sizeof(ListNode));
        node->val = (sum + carry) % 10;
        node->next = NULL;
        carry = (sum + carry) / 10;
        if (pa == NULL) {
            pa = la = node;
        } else {
            pa->next = node;
            pa = pa->next;
        }

        if (p1) p1 = p1->next;
        if (p2) p2 = p2->next;
    }
    if (carry > 0) {
        ListNode* node = malloc(sizeof(ListNode));
        node->val = carry;
        node->next = NULL;

        if (pa == NULL) {
            pa = la = node;
        } else {
            pa->next = node;
            pa = pa->next;
        }
    }

    return la;
}

int main()
{
    ListNode* l1 = NULL, *l2 = NULL;
    ListNode* p1 = NULL, *p2 = NULL;
    srand((unsigned)time(NULL));

    int i = 0, j = 0;
    for (i = 0; i < 3; i++)
    {
        ListNode* node = malloc(sizeof(ListNode));
        node->val = rand()%(9-1+1)+1;
        node->next = NULL;

        if (p1 == NULL) {
            p1 = l1 = node;
        } else {
            p1->next = node;
            p1 = p1->next;
        }
    }

    printf("print l1:\n\t");
    p1 = l1;
    while (p1) {
        printf("%d ", p1->val);
        p1 = p1->next;
    }
    printf("\n");

    for (j = 0; j < 3; j++)
    {
        ListNode* node = malloc(sizeof(ListNode));
        node->val = rand()%(9-1+1)+1;
        node->next = NULL;

        if (p2 == NULL) {
            p2 = l2 = node;
        } else {
            p2->next = node;
            p2 = p2->next;
        }
    }

    printf("print l2:\n\t");
    p2 = l2;
    while (p2) {
        printf("%d ", p2->val);
        p2 = p2->next;
    }
    printf("\n");

    ListNode* la = NULL, * pa = NULL;
    la = pa = addTwoNumbers(l1, l2);
    printf("print la:\n\t");
    while (pa) {
        printf("%d ", pa->val);
        pa = pa->next;
    }
    printf("\n");

    for (i = 0; i < 7; i++) {
        printf("%c ", 'a' + rand()%(26));
    }
    printf("\n");
}
