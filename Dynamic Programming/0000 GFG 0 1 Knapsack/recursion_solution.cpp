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

            return solve(n,W,val,wt);

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