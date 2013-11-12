/**
  * Say you have an array for which the ith element
  * is the price of a given stock on day i.
  *
  * Design an algorithm to find the maximum profit.
  * You may complete as many transactions as you like
  * (ie, buy one and sell one share of the stock multiple times).
  * However, you may not engage in multiple transactions at
  * the same time (ie, you must sell the stock before you buy again).
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
        vector<int> prices;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &tmp);
            prices.push_back(tmp);
        }

        tmp = s.maxProfit(prices);
        printf("%d\n", tmp);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

