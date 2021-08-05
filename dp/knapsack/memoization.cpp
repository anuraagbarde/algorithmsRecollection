#include <bits/stdc++.h>

using namespace std;

//adding memoziation
// The row and col of the dp matrix will be the paramaters that are changing accross the recursive stack, here it is the capacity and n itself

#define N 100   //max value as given in the problem
#define W 10000 //max value as given in the problem
int dp[N + 1][W + 1];
// dont forget to initialize it with -1 in main() function

int kp(vector<int> &wt, vector<int> &val, int capacity, int n)
{

    //base condition
    //smallest valid input
    if (capacity == 0 || n == 0)
        return 0; // max profit is 0 for this case

    //adding memoziation -> read
    //if the dp matrix has been calculated before, then return it
    if (dp[n][capacity] != -1)
    {
        return dp[n][capacity];
    }

    int profit = 0;
    //choice diagram
    if (wt[n - 1] <= capacity)
    {
        profit = max(kp(wt, val, capacity - wt[n - 1], n - 1) + val[n - 1], kp(wt, val, capacity, n - 1));

        //adding memoziation -> write
        dp[n][capacity] = profit;
    }
    else if (wt[n - 1] > capacity)
    {
        profit = kp(wt, val, capacity, n - 1);

        //adding memoziation -> write
        dp[n][capacity] = profit;
    }
    return profit;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int capacity = 7;

    int n = wt.size();

    int maxValue = kp(wt, val, capacity, n);

    cout << maxValue << endl;

    return 0;
}