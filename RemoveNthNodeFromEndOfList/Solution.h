#ifndef SOLUTION_H
#define SOLUTION_H

#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once
        // and is reused by each test case.
        ListNode * p = head, * q = head;
        if (p == NULL)
            return head;

        int i;
        for (i = 1; p->next != NULL; ++i) {
            p = p->next;
            if (i > n)
                q = q->next;
        }

        if (q == head && i == n) {
            head = head->next;
            free(q);
        } else {
            p = q->next;
            q->next = p->next;
            free(p);
        }

        return head;
    }
};

#endif // SOLUTION_H
