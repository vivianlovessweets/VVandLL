/**
  * Given a linked list, swap every two adjacent
  * nodes and return its head.
  *
  * For example,
  * Given 1->2->3->4, you should return the list
  * as 2->1->4->3.
  * Your algorithm should use only constant space.
  * You may not modify the values in the list,
  * only nodes itself can be changed.
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
        ListNode * ans = s.swapPairs(head);

        for (p = ans; p != NULL; p = p->next) {
            printf("%d\t", p->val);
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

