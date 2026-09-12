#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(int n, int W, vector<int>&val, vector<int>&wt){

            // Base condition
            if( W == 0 || n ==0 ){
                return 0;
            }

            int pick = 0;
            if(wt[n-1] <= W){
                pick = val[n-1] + solve(n-1-1,W-wt[n-1],val,wt);
            }
            int notPick =  solve(n-1,W,val,wt);

            return max(pick,notPick);
        }


        int knapsack(int W, vector<int>&val, vector<int>&wt){
            int n = wt.size();

            vector<vector<int>>dp(n+1,vector<int>(W+1,-1));

            for(int i=0;i<=n;i++){
                for(int j=0;j<=W;j++){
                    if(i == 0 || j == 0){
                        dp[i][j] = 0;
                    } 

                    else{
                        if(wt[i-1] <= j){
                            dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
                        }
                        else {
                            dp[i][j] = dp[i-1][j];
                        }
                    }
                }
            }

            return dp[n][W];

        }
};

int main()
{
    int W = 4;
    vector<int>val = {1,2,3};
    vector<int>wt = {4,5,1};
    Solution obj;
    cout<<obj.knapsack(W,val,wt);
    return 0;
}