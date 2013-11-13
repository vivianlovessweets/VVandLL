#ifndef SOLUTION_H
#define SOLUTION_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode * p = head, *pre = head, * q;

        while (p != NULL && p->next != NULL) {
            q = p->next;

            p->next = q->next;
            q->next = p;
            if (head == pre)
                head = q;
            else
                pre->next = q;

            pre = p;
            p = p->next;
        }

        return head;
    }
};

#endif // SOLUTION_H
