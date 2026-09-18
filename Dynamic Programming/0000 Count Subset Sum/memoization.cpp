#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, vector<int> &arr, int target, vector<vector<int>> &dp)
    {

        if (n == 0)
            return target == 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int pick = 0;
        if (arr[n - 1] <= target)
        {
            pick = solve(n - 1, arr, target - arr[n - 1], dp);
        }
        int notPick = solve(n - 1, arr, target, dp);

        return dp[n][target] = pick + notPick;
    }
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, arr, target, dp);
    }
};

int main()
{
    return 0;
}