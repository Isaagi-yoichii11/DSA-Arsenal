#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));

        for(int i=0;i<=sum;i++){
            dp[0][i] = 0;
        }

        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j = 1;j<=sum; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

int main()
{
    int sum = 9;
    vector<int>arr = {3,34,4,12,5,2};
    Solution obj;
    obj.isSubsetSum(arr,sum);
    return 0;
}