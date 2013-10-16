/**
  * Given a sorted linked list, delete all nodes
  * that have duplicate numbers, leaving only
  * distinct numbers from the original list.
  *
  * For example,
  * Given 1->2->3->3->4->4->5, return 1->2->5.
  * Given 1->1->1->2->3, return 2->3.
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
        ListNode * ans = s.deleteDuplicates(head);

        for (p = ans; p != NULL; p = p->next) {
            printf("%d\t", p->val);
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

