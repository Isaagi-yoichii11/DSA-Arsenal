#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &text1,int n,string &text2 , int m,vector<vector<int>>&dp){
        if(n == 0 || m == 0) return dp[n][m] = 0;

        if(dp[n][m] != -1){
            // cout<<"Akash"<<endl;
            return dp[n][m];

        }

        int count = 0;
        if(text1[n-1] == text2[m-1]){
            count = 1+ solve(text1,n-1,text2,m-1,dp);
        }
        else{
            count = max(solve(text1,n-1,text2,m,dp) , solve(text1,n,text2,m-1,dp));
        }

        return dp[n][m] = count;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(text1,n,text2,m,dp);
    }
};

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    Solution obj;
    obj.longestCommonSubsequence(text1,text2);
    return 0;
}