// https://leetcode.com/problems/partition-equal-subset-sum/

// 416. Partition Equal Subset Sum
// Given a non-empty array nums containing only positive integers,
// find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

#include <bits/stdc++.h>
using namespace std;

bool isSubsetPossible(vector<int> &nums, int n, int k, vector<vector<int>> &dp)
{

    //base case
    // if n==0 return 0
    // if k==0 return 1 // null is always a subset
    // the order is important of if because both if will write on the [0][0] box, only the last if will persist
    if (n == 0)
    {
        dp[n][k] = 0;
        return 0;
    }
    if (k == 0)
    {
        dp[n][k] = 1;
        return 1;
    }

    //choice diagram
    bool ans = false;
    if (dp[n][k] != -1)
    {
        return ans = dp[n][k];
    }

    // current element will fit into the subset
    else if (nums[n - 1] <= k)
    {
        // Try both the cases, include the current object and dont include it, even if one results in the subset being of k size return true, that yes it is possible.
        ans = isSubsetPossible(nums, n - 1, k - nums[n - 1], dp) || isSubsetPossible(nums, n - 1, k, dp);
        dp[n][k] = ans;
        return ans;
    }
    //current element is too big to fit into the bag
    else if (nums[n - 1] > k)
    {
        ans = isSubsetPossible(nums, n - 1, k, dp);
        dp[n][k] = ans;
        return ans;
    }

    return ans;
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (auto i : nums)
    {
        sum += i;
    }

    if (sum % 2 == 1)
        return false;
    else if (sum % 2 == 0)
    {
        int k = sum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

        return isSubsetPossible(nums, n, k, dp);
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 9};
    cout << canPartition(nums);
    return 0;
}