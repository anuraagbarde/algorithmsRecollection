#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/?category[]=Dynamic%20Programming&category[]=Dynamic%20Programming&page=4&query=category[]Dynamic%20Programmingpage4category[]Dynamic%20Programming#
class Solution
{
public:
    int dp[101][10001]; // n x sum
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }
    bool isSubsetSum(int N, int arr[], int sum)
    {
        // code here
        //base condition
        if (sum <= 0)
        {
            return true;
        }

        if (N <= 0)
        {
            return false;
        }

        int ans = 0;

        int curr = arr[N - 1];

        //see if value is already memoized
        if (dp[N][sum] != -1)
        {
            ans = dp[N][sum];
            return ans;
        }
        //choice diagram
        else if (curr == sum)
        {
            ans = true;
        }
        else if (curr > sum)
        {
            // reject the current element
            ans = isSubsetSum(N - 1, arr, sum);
        }
        else if (curr < sum)
        {
            int considerCurr = isSubsetSum(N - 1, arr, sum - curr);
            int dontConsiderCurr = isSubsetSum(N - 1, arr, sum);
            ans = considerCurr || dontConsiderCurr;
        }
        //add to dp for memoization
        dp[N][sum] = ans;
        return ans;
    }
};
