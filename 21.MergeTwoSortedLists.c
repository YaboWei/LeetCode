#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct _ListNode {
    int val;
    struct _ListNode *next;
};

typedef struct _ListNode ListNode;
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1, *p2 = l2;
    ListNode* merge = NULL, *pme = NULL;
    
    while (p1 && p2) {
        ListNode* p = malloc(sizeof(ListNode));
        if (p1->val > p2->val) {
            printf("get %d from p2\n", p2->val);
            p->val = p2->val;
            p->next = NULL;
            p2 = p2->next;
        } else {
            printf("get %d from p1\n", p1->val);
            p->val = p1->val;
            p->next = NULL;
            p1 = p1->next;
        }

        if (merge == NULL) {
            merge = pme = p;
        } else {
            pme->next = p;
            pme = pme->next;
        }
    }

    if (p1) {
        ListNode* p = malloc(sizeof(ListNode));
        p->val = p1->val;
        p->next = NULL;
        printf("get %d from p1\n", p1->val);

        if (merge == NULL) {
            merge = pme = p;
        } else {
            pme->next = p;
            pme = pme->next;
        }

        p1 = p1->next;
    }
    if (p2) {
        ListNode* p = malloc(sizeof(ListNode));
        p->val = p2->val;
        p->next = NULL;
        printf("get %d from p2\n", p2->val);

        if (merge == NULL) {
            merge = pme = p;
        } else {
            pme->next = p;
            pme = pme->next;
        }

        p2 = p2->next;
    }

    return merge;
}
int main()
{
    ListNode* l1 = NULL, *l2 = NULL;
    ListNode* p1 = NULL, *p2 = NULL;

    int i = 0, j = 0;
    for (i = 0; i < 3; i++)
    {
        ListNode* node = malloc(sizeof(ListNode));
        node->val = 2*i;
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
        node->val = 2*j + 1;
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

    ListNode* merge = mergeTwoLists(l1, l2);
    if (merge == NULL) {
        return -1;
    }
    printf("print merge:\n\t");
    ListNode* pme = merge;
    while (pme) {
        printf("%d ", pme->val);
        pme = pme->next;
    }
    printf("\n");

    return 0;
}
