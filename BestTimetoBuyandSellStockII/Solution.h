#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once
        // and is reused by each test case.
        int profit = 0, len = prices.size();

        for (int i = 1; i < len; ++i) {
            int delta = prices[i] - prices[i-1];
            if (delta > 0) {
                profit += delta;
            }
        }

        return profit;
    }
};

#endif // SOLUTION_H
