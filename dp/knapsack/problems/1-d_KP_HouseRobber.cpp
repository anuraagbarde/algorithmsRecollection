
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int dp[100 + 1];
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }

    int robHelper(vector<int> &nums, int n)
    {
        if (n <= 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        //choice diagram
        // include the current one and then take result of n-2
        int a1 = robHelper(nums, n - 2) + nums[n - 1];

        //dont include current one, use the one before
        int a2 = robHelper(nums, n - 1);

        dp[n] = max(a1, a2);
        return dp[n];
    }

    int rob(vector<int> &nums)
    {

        return robHelper(nums, nums.size());
    }
};