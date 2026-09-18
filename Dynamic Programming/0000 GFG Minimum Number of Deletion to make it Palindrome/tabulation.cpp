#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
            int n = text1.size();
            int m = text2.size();

            vector<vector<int>>dp(n+1,vector<int>(m+1,0));

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(text1[i-1] == text2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                    }
                }
            }

            return dp[n][m];
        }
    int minDeletions(string &s) {
        // code here
        string t = s;
        reverse(t.begin(),t.end());
        int ans = longestCommonSubsequence(s,t);
        int n = t.size();
        return (n - ans);
    }
};

int main()
{
    string text1 = "abcde";
    Solution obj;
    obj.minDeletions(text1);
    return 0;
}