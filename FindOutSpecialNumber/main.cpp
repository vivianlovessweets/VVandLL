/**
  * Every integer in array A appears 3 times
  * except X. what is the fastest way to find out X?
  */
#include <iostream>

using namespace std;

#define MAX_LEN 10000000

int count, maxInx;
int nums[MAX_LEN];
int sum[32];

void bitSum()
{
    memset(sum, 0, 32 * sizeof(int));
    maxInx = 0;

    for (int i = 0; i < count; ++i)
    {
        int j, cur = nums[i];
        for (j = 0; cur != 0; ++j)
        {
            sum[j] += (cur % 2);
            cur /= 2;
        }
        if (j > maxInx)
            maxInx = j;
    }
}

int calculateResult()
{
    int mul = 1, result = 0;

    for (int i = 0; i < maxInx; ++i)
    {
        result += (mul * (sum[i] % 3));
        mul *= 2;
    }

    return result;
}

int main()
{
    freopen("inputs.in", "r", stdin);
    freopen("outputs.out", "w", stdout);

    while (scanf("%d", &count) > 0)
    {
        for (int i = 0; i < count; ++i)
            scanf("%d", &nums[i]);
//            cin >> nums[i];

        bitSum();

        int result = calculateResult();
        printf("%d\n", result);
//        cout << result << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

