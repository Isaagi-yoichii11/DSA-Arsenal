#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int n, vector<int> &arr, int sum)
    {

        if (sum == 0)
        {
            return true;
        }
        if (n == 0)
        {
            return false;
        }

        bool pick = false;
        if (arr[n - 1] <= sum)
        {
            pick = solve(n - 1, arr, sum - arr[n - 1]);
        }

        bool notPick = solve(n - 1, arr, sum);

        return pick | notPick;
    }
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();

        return solve(n, arr, sum);
    }
};

int main()
{

    return 0;
}