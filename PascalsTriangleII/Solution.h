#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once
        // and is reused by each test case.
        vector<int> a, b;
        vector<int> *cur = &a, *pre = &b;

        for (int i = 0; i <= rowIndex; ++i) {
            cur->clear();
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i)
                    cur->push_back(1);
                else {
                    int tmp = (*pre)[j - 1] + (*pre)[j];
                    cur->push_back(tmp);
                }
            }

            vector<int> *tmp = cur;
            cur = pre;
            pre = tmp;
        }

        return *pre;
    }
};

#endif // SOLUTION_H
