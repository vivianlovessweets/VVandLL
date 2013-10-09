#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> results;
        int len = ratings.size();
        for (int i = 0; i < len; ++i) {
            if (i == 0 || ratings[i] <= ratings[i-1]) {
                results.push_back(1);
            } else {
                results.push_back(results[i-1]+1);
            }
        }

        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                int tmp = results[i+1] + 1;
                if (tmp > results[i]) {
                    results[i] = tmp;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += results[i];
        }

        return sum;
    }
};

#endif // SOLUTION_H
