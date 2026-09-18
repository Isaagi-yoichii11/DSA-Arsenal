#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return ans;
    }
};

int main()
{
    string text1 = "abcd";
    string text2 = "acdb";
    Solution obj;
    int result = obj.longestCommonSubsequence(text1, text2);
    cout << result;
    return 0;
}