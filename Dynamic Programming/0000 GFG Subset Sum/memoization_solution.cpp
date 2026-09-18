#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int n, vector<int> &arr, int sum,vector<vector<int>>&dp)
    {
        // Base condition
        if (sum == 0)
        {
            return dp[n][sum] = true;
        }
        if (n == 0)
        {
            return dp[n][sum] = false;
        }

        if(dp[n][sum] != -1){
            return dp[n][sum];
        }

        bool pick = false;
        if (arr[n - 1] <= sum)
        {
            pick = solve(n - 1, arr, sum - arr[n - 1],dp);
        }

        bool notPick = solve(n - 1, arr, sum,dp);

        return dp[n][sum] =  pick | notPick;
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(n, arr, sum,dp);
    }
};

int main()
{

    return 0;
}