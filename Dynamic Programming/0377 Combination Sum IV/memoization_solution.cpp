#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

        int solve(vector<int>&nums,int target, int n,vector<int>&dp){
            
            // Base condition
            if(target == 0) return dp[target] = 1;

            // if(n == 0) return dp[target] = 0;
            
            if(dp[target] != -1){
                return dp[target];
            }

            int count = 0;
            for(int i=0;i<n;i++){
                if(nums[i] <= target){
                    count += solve(nums,target-nums[i],n,dp);
                }
            }

            return dp[target] = count;
        }
        int combinationSum4(vector<int>nums,int target){
            
            int n = nums.size();
            vector<int>dp(target+1,-1);
            return solve(nums,target,n,dp);
        }
};


int main()
{
    int target = 4;
    vector<int>nums = {1,2,3};

    Solution obj;
    obj.combinationSum4(nums,target);
    return 0;
}