/**
  * Given a linked list, remove the nth node from the end of list and return its head.
  * For example,
  * Given linked list: 1->2->3->4->5, and n = 2.
  * After removing the second node from the end, the linked list becomes 1->2->3->5.
  * Note:
  * Given n will always be valid.
  * Try to do this in one pass.
  */
#include <iostream>
#include "Solution.h"

using namespace std;

int main()
{
    freopen("inputs.in", "r", stdin);
    freopen("outputs.out", "w", stdout);

    Solution s;

    int T, N, tmp;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        scanf("%d", &N);
        ListNode * head = NULL, * tail, * p;
        while (N > 0) {
            --N;
            scanf("%d", &tmp);
            p = new ListNode(tmp);
            if (head != NULL){
                tail->next = p;
                tail = p;
            }
            else {
                head = p;
                tail = p;
            }
        }
        scanf("%d", &tmp);
        ListNode * ans = s.removeNthFromEnd(head, tmp);

        for (p = ans; p != NULL; p = p->next) {
            printf("%d\t", p->val);
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
