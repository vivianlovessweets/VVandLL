#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once
        // and is reused by each test case.
        vector<vector<int> >  result;

        for (int i = 0; i < numRows; ++i) {
            vector<int> ires;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i)
                    ires.push_back(1);
                else {
                    int tmp = result[i - 1][j - 1] + result[i - 1][j];
                    ires.push_back(tmp);
                }
            }
            result.push_back(ires);
        }

        return result;
    }
};

#endif // SOLUTION_H
