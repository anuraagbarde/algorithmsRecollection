// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        int dp[n + 1][sum + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= sum; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j - arr[i - 1] >= 0)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        int ans = 0;
        for (int i = (sum) / 2; i >= 0; i--)
        {
            if (dp[n][i])
            {
                ans = i;
                break;
            }
        }
        //cout<<sum<<' '<<ans<<endl;
        return abs((sum - ans) - ans);
    }
};
