/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

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

void removeNthFromEnd(ListNode* head, int n) {
    ListNode* p1 = head, * p2 = head;
    int i;
    for (i = 0; i < n+1; i++) {
        if (p1) {
            p1 = p1->next;
        }
    }

    while (p1) {
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("p2->val: %d\n", p2->val);
    p2->next = p2->next->next;

    return;
}

int main()
{
    ListNode* l1 = NULL;
    ListNode* p1 = l1;
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        ListNode* node = malloc(sizeof(ListNode));
        node->val = i + 1;
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

    removeNthFromEnd(l1, 2);
    printf("print l1:\n\t");
    p1 = l1;
    while (p1) {
        printf("%d ", p1->val);
        p1 = p1->next;
    }
    printf("\n");
}
