#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string &s, int i, int j){
        
        while(i <= j){
            if(s[i] != s[j])return false;
            else{
                i++;
                j--;
            }
        }
        
        return true;
    }
    void helper(string &s,vector<vector<bool>>&pal){
        // string text = "akash";
        int n = s.size();
        
        // bool pal[n][n];

        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(j < i){
                    pal[i][j] =  false;
                }
                else if(i == j){
                    pal[i][j] = true;
                }
                else{
                    pal[i][j] = (s[i] == s[j]) && pal[i+1][j-1];
                }
            }
        }
    }

    int solve(string &s, int i, int j,vector<vector<int>>&dp,vector<vector<bool>>&pal){
        
        if(i >= j || pal[i][j])
            return dp[i][j] = 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int res = INT_MAX;
        int ans;
        
        for(int k=i;k<j;k++){
            ans = 1 + solve(s,i,k,dp,pal) + solve(s,k+1,j,dp,pal);
            res = min(ans,res);
        }
        
        return dp[i][j] = res;
    }

    int palPartition(string &s) {
        // code here
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<vector<bool>>pal(n,vector<bool>(n));
        helper(s,pal);
        
        return solve(s,0,n-1,dp,pal);
        
    }
    
};

int main()
{
    string s = "axxzxy";
    Solution obj;
    obj.palPartition(s);
    return 0;
}