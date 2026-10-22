#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

class Solution
{
public:
    string shortestCommonSupersequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        string ans = "";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    // ans += text1[i-1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n;
        int j = m;
        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                ans.push_back(text1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    ans.push_back(text2[j - 1]);
                    j--;
                }
                else
                {
                    ans.push_back(text1[i - 1]);
                    i--;
                }
            }
        }

        while (j > 0)
        {
            ans.push_back(text2[j - 1]);
            j--;
        }

        while (i > 0)
        {
            ans.push_back(text1[i - 1]);
            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    string text1 = "abac";
    string text2 = "cab";
    Solution obj;
    obj.shortestCommonSupersequence(text1, text2);
    return 0;
}