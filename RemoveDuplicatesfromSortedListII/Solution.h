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
        ListNode * p = head, * q = head;
        if (p == NULL)
            return head;

        bool same = false;
        int pre = p->val - 1;
        while (p != NULL) {
            if (same) {
                pre = p->val;
                if (head == p) {
                    head = p->next;
                    q = head;
                    free(p);
                    p = q;
                } else {
                    q->next = p->next;
                    free(p);
                    p = q->next;
                }
                same = false;
            } else {
                if (pre == p->val) {
                    same = true;
                    continue;
                } else {
                    if (p->next == NULL)
                        break;
                    if (p->val == p->next->val)
                        same = true;
                    else {
                        p = p->next;
                        if (q->next != p)
                            q = q->next;
                    }
                }
            }
        }

        return head;
    }
};

#endif // SOLUTION_H
