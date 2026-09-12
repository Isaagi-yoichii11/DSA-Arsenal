#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 1e9;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // Make the dp table
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INF));

        // Base conditions
        for(int i=0;i<=amount;i++){
            dp[0][i] = INF;
        }

        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        // Main logic
        for(int i=1;i<=n;i++){
            for(int j = 1; j <= amount; j++){
                
                // if 
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j], (1+dp[i][j-coins[i-1]]));
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int ans = dp[n][amount];
        
        return ans == INF ? -1 : dp[n][amount];
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