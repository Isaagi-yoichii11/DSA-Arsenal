#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int INF = 1e9;
    int solve(int idx, vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (idx < 0)
        {
            return INF;
        }
        int pick = INF;
        if (coins[idx] <= amount)
        {
            pick = 1 + solve(idx, coins, amount - coins[idx]);
        }

        int notPick = solve(idx - 1, coins, amount);

        return min(pick, notPick);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = solve(coins.size() - 1, coins, amount);
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