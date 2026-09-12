#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int change(int amount,vector<int>&coins){
            int n = coins.size();

            vector<vector<int>>dp(n+1,vector<int>(amount +1,0));
            
            // If we dont have to make any amount, then there is only one way, by choosing nothing
            for(int i=0;i<=n;i++){
                dp[i][0] = 1;
            }

            for(int i=1;i<=n;i++){
                for(int j=1;j<=amount;j++){
                    if (coins[i - 1] <= j) {
                        long long ways = 1LL*dp[i][j-coins[i-1]] + dp[i-1][j];

                        // Prevent overflow
                        dp[i][j] = min(ways,1LL*INT_MAX);
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }

            return dp[n][amount];
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