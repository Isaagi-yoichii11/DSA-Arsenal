#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

        int solve(vector<int>&nums,int target, int n){
            
            // Base condition
            if(target == 0) return 1;

            // if(n == 0) return 0;
            
            int count = 0;
            for(int i=0;i<n;i++){
                if(nums[i] <= target){
                    count += solve(nums,target-nums[i],n);
                }
            }

            return count;
        }
        int combinationSum4(vector<int>nums,int target){
            
            int n = nums.size();
            return solve(nums,target,n);
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