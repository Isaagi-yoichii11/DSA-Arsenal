#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        int solve(vector<int>&nums,int target, int n, int count){

            if(target == 0) return 1;

            if(n == 0) return 0;

            int pick = 0;
            if (nums[n-1] <= target){
                pick = solve(nums,target-nums[n-1],n-1,count);
            }

            int notPick = solve(nums,target,n-1,count);




            return pick + notPick;
        }

        int countSubsequences(vector<int>&nums, int target){
            
            int n = nums.size();
            int ans = solve(nums,target,n,0);

            cout<<ans<<endl;

        }

};


int main()
{
    Solution obj;
    vector<int>nums = {8,1,9,5,5,10};
    int target = 10;

    obj.countSubsequences(nums,target);
    return 0;
}