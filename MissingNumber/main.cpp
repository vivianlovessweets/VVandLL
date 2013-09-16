/**
  * Given a disordered array of integers,
  * find out the first integer that is greater than 0
  * and not in the array.
  * e.g. [1,2,0] -> 3, [3,4,-1,1] -> 2
  * Space: O(1) Time: O(n)
  */

#include <iostream>

using namespace std;

#define MAX_LEN 10000000

int count;
int nums[MAX_LEN];

void swapToSort()
{
    for (int i = 0; i < count; )
    {
        int tar, cur = nums[i];

        if (cur > count || cur <= 0)
            nums[i] = 0;
        else if (cur != (i + 1))
        {
            tar = nums[cur - 1];
            if (tar == cur)
                nums[i] = 0;
            else
            {
                nums[i] = tar;
                nums[cur - 1] = cur;
            }
        }

        if (cur <= (i + 1))
            ++i;
    }
}

int main()
{
    freopen("inputs.in", "r", stdin);
    freopen("outputs.out", "w", stdout);

    while (scanf("%d", &count) > 0)
    {
        for (int i = 0; i < count; ++i)
            scanf("%d", &nums[i]);

        swapToSort();

        int result = 0;
        for (int i = 0; i < count; ++i)
        {
            if (nums[i] != (i + 1))
            {
                result = i + 1;
                break;
            }
        }

        if (result == 0)
            result = count + 1;

        printf("%d\n", result);

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

