#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = strs.size();
        if (len == 0)
            return "";

        string pre = strs[0];
        for (int i = 1; i < len; ++i) {
            string cur = strs[i];
            int tlen = min(pre.size(), cur.size());
            int j;
            for (j = 0; j < tlen; ++j) {
                if (pre[j] != cur[j])
                    break;
            }

            pre = pre.substr(0, j);
        }

        return pre;
    }
};

#endif // SOLUTION_H
