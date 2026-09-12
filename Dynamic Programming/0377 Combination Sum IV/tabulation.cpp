#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> nums, int target) {

        int n = nums.size();

        vector<long long> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (num <= i) {
                    if (dp[i] > INT_MAX - dp[i - num])
                        dp[i] = INT_MAX;
                    else
                        dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
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