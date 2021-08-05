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
    // printf("capacity=%d, n=%d \n", capacity, n);
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            //base case
            if (i == 0 || j == 0)
            {
                // cout << "A";
                dp[i][j] = 0;
            }

            //if the item is included in the knapsack
            // pay attention it is i-1 and not i
            else if (wt[i - 1] <= j)
            {
                // cout << "B";
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            //if the item is not included in the knapsack
            else if (wt[i - 1] > j)
            {
                // cout << "C";
                dp[i][j] = dp[i - 1][j];
            }
            // printf("%d %d ", i, j);
            // cout << dp[i][j] << " | ";
        }
        // cout << endl;
    }

    return dp[n][capacity];
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