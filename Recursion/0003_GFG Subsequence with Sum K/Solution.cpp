#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&nums, int target, int sum,int n,bool picked){


    if(n == 0){
        return (sum == target) && picked;
    }

    // bool pick = false;

    bool pick = solve(nums,target,sum+nums[n-1],n-1,true);


    bool notPick = solve(nums,target,sum,n-1,picked);

    return pick || notPick;

}

bool checkSubsequenceSum(vector<int>&nums, int target){
    int n = nums.size();

    return solve(nums,target,0,n,false);


}

int main()
{
    vector<int>nums = {7,8,-1,-2};
    if(checkSubsequenceSum(nums,0)){
        cout<<"Present"<<endl;
    }
    else {
        cout<<"Not present"<<endl;
    }
    return 0;
}