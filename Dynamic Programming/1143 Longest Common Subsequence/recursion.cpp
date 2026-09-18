#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string text1,int n,string text2 , int m){
        if(n == 0 || m == 0) return 0;

        int count = 0;
        if(text1[n-1] == text2[m-1]){
            count = 1+ solve(text1,n-1,text2,m-1);
        }
        else{
            count = max(solve(text1,n-1,text2,m) , solve(text1,n,text2,m-1));
        }

        return count;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        return solve(text1,n,text2,m);
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