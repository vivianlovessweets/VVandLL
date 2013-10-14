/**
  * Given an index k, return the kth row of the Pascal's triangle.
  *
  * For example, given k = 3,
  * Return [1,3,3,1].
  *
  * Note:
  * Could you optimize your algorithm to use only O(k) extra space?
  */

#include <iostream>
#include "Solution.h"

using namespace std;

int main()
{
    freopen("inputs.in", "r", stdin);
    freopen("outputs.out", "w", stdout);

    Solution s;

    int T, N;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        scanf("%d", &N);
        vector<int> ans = s.getRow(N);

        int len = ans.size();
        for (int i = 0; i < len; ++i) {
            printf("%d\t", ans[i]);
        }
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

