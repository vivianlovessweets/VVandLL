/**
  * Given numRows, generate the first numRows of Pascal's triangle.
  *
  * For example, given numRows = 5,
  * Return
  *
  * [
  *     [1],
  *     [1,1],
  *     [1,2,1],
  *     [1,3,3,1],
  *     [1,4,6,4,1]
  * ]
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
        vector<vector<int> > ans = s.generate(N);

        int len = ans.size();
        for (int i = 0; i < len; ++i) {
            vector<int> ians = ans[i];
            int ilen = ians.size();
            for (int j = 0; j < ilen; ++j)
                printf("%d\t", ians[j]);
            printf("\n");
        }
        printf("--------------------\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

