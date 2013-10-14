#ifndef SOLUTION_H
#define SOLUTION_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once
        // and is reused by each test case.
        ListNode * p = head, * q;
        if (p == NULL)
            return head;

        while (p->next != NULL) {
            q = p->next;
            if (p->val == q->val) {
                p->next = q->next;
                free(q);
            } else {
                p = q;
            }
        }

        return head;
    }
};

#endif // SOLUTION_H
