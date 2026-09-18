#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int solve(int n, vector<int>&arr, int target){
            
            if(n == 0) return target == 0;

            int pick = 0;
            if(arr[n-1] <= target){
                pick = solve(n-1,arr,target-arr[n-1]);
            }
            int notPick = solve(n-1,arr,target);

            return pick + notPick;
        }
        int perfectSum(vector<int>&arr, int target){
            int n = arr.size();

            return solve(n,arr,target);

        }  
};

int main()
{
    return 0;
}