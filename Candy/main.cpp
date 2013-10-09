/**
  * There are N children standing in a line.
  * Each child is assigned a rating value.
  * You are giving candies to these children subjected
  * to the following requirements:
  * Each child must have at least one candy.
  * Children with a higher rating get more candies
  * than their neighbors.
  * What is the minimum candies you must give?
  *
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
        int tmp;
        vector<int> test;
        while (N > 0) {
            --N;
            scanf("%d", &tmp);
            test.push_back(tmp);
        }

        int ans = s.candy(test);
        printf("%d\n", ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

