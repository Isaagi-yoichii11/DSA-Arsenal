#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 1e9;
    int solve(int idx, vector<int>& coins, int amount,
              vector<vector<int>>& dp) {

        if (amount == 0)
            return dp[idx][amount] = 0;
        
        if (idx < 0) {
            return INF;
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int pick = INF;
        if (coins[idx] <= amount) {
            pick = 1 + solve(idx, coins, amount - coins[idx], dp);
        }

        int notPick = solve(idx - 1, coins, amount, dp);

        return dp[idx][amount] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(coins.size() - 1, coins, amount, dp);
        if (ans == INF)
            return -1;

        return ans;
    }
};

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution obj;
    obj.coinChange(coins,amount);
    return 0;
}