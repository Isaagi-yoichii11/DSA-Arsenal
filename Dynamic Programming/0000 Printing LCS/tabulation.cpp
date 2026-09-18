#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        string ans = "";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    // ans += text1[i-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        for(int i=0;i<n+1;i++){
            for(int j = 0;j<m+1;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;;
        }
    
        int i = n;
        int j = m;
        while(i>0 && j >0){
            if(text1[i-1] == text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    j--;
                }
                else{
                    i--;
                }
            }

        }

        reverse(ans.begin(),ans.end());
        cout<<ans;
        return dp[n][m];
    }
};

int main()
{
    string text1 = "abcde";
    string text2 = "acefgb";
    Solution obj;
    obj.longestCommonSubsequence(text1,text2);
    return 0;
}