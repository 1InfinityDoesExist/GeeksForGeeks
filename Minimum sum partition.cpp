#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int minimumSumPartition(vector<int> &A);
};
Solution::Solution(){}
int Solution::minimumSumPartition(vector<int> &A)
{
    int n = A.size();
    int sum (0);
    for(int iter = 0; iter < n; iter++)
    {
        sum = sum + A[iter];
    }
    int dp[n+1][sum+1];
    for(int jter = 0; jter <= n ;jter++)
    {
        dp[jter][0] = true;
    }
    for(int iter = 1; iter <= sum; iter++)
    {
        dp[0][iter] = false;
    }
    for(int iter = 1; iter <= n; iter++)
    {
        for(int jter = 1; jter <= sum; jter++)
        {
            dp[iter][jter] = dp[iter-1][jter];
            if(jter >= A[iter-1])
            {
                dp[iter][jter] |= dp[iter-1][jter - A[iter-1]];
            }
        }
    }
    int diff = INT_MAX;
    for(int jter = sum/2; jter >= 0; jter--)
    {
        if(dp[n][jter] == true)
        {
            diff = sum-2*jter;
            break;
        }
    }
    return diff;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.minimumSumPartition(A);
        cout << ans <<endl;
    }
    return 0;
}
