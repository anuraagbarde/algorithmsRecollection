#include <bits/stdc++.h>

using namespace std;

int kp(vector<int> &wt, vector<int> &val, int capacity, int n)
{

    //base condition
    //smallest valid input
    if (capacity == 0 || n == 0)
        return 0; // max profit is 0 for this case

    int profit = 0;
    //choice diagram
    if (wt[n - 1] <= capacity)
    {
        profit = max(kp(wt, val, capacity - wt[n - 1], n - 1) + val[n-1], kp(wt, val, capacity, n - 1));
    }
    else if (wt[n - 1] > capacity)
    {
        profit = kp(wt, val, capacity, n - 1);
    }
    return profit;
}

int main()
{
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int capacity = 7;

    int n = wt.size();

    int maxValue = kp(wt, val, capacity, n);

    cout << maxValue << endl;

    return 0;
}