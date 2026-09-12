#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

        int solve(int n, vector<int>&coins, int amount){
            
            // Base condition
            if(amount == 0) return 1;

            // Nothing to choose from
            if(n == 0) return 0;

            int pick = 0;
            
            if(coins[n-1] <= amount){
                pick = solve(n,coins,amount-coins[n-1]);
            }

            int notPick = solve(n-1,coins,amount);

            return pick + notPick;

        }
        int change(int amount,vector<int>&coins){
            
            int n = coins.size();
            return solve(n,coins, amount);
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