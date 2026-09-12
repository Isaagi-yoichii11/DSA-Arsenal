#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

        int solve(int n, vector<int>&coins, int amount,vector<vector<int>>&dp){
            
            // Base condition
            if(amount == 0) return dp[n][amount] = 1;

            // Nothing to choose from
            if(n == 0) return dp[n][amount] = 0;

            if(dp[n][amount] != -1){
                return dp[n][amount];
            }

            int pick = 0;
            
            if(coins[n-1] <= amount){
                pick = solve(n,coins,amount-coins[n-1],dp);
            }

            int notPick = solve(n-1,coins,amount,dp);

            return dp[n][amount] = pick + notPick;

        }
        int change(int amount,vector<int>&coins){
            
            int n = coins.size();
            vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

            return solve(n,coins, amount,dp);
        }
};

int main()
{
    int amount = 5;
    vector<int>coins = {1,2,5};
    Solution obj;
    obj.change(amount,coins);
    return 0;
}