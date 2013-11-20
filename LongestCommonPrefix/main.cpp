/**
  * Write a function to find the longest common
  * prefix string amongst an array of strings.
  */

#include <iostream>
#include <string>
#include "Solution.h"

using namespace std;

int main()
{
    freopen("inputs.in", "r", stdin);
    freopen("outputs.out", "w", stdout);

    Solution s;

    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        int N;
        scanf("%d", &N);
        string instr;
        vector<string> strs;
        for (; N > 0; --N) {
            cin >> instr;
            strs.push_back(instr);
        }

        string result = s
                .longestCommonPrefix(strs);
        cout << result << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

