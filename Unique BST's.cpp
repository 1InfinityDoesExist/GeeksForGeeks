#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int uniqueBST(int n);
};
Solution::Solution(){}
int Solution::uniqueBST(int n)
{
    int *dp = (int *)malloc(sizeof(int) * n+1);
    for(int iter = 0; iter <= n; iter++)
    {
        dp[iter] = 0;
    }
    dp[0] = dp[1] = 1;
    for(int iter = 2; iter <= n ;iter++)
    {
        for(int jter = 1; jter <= iter/2; jter++)
        {
            dp[iter] += dp[jter-1]*dp[iter-jter];
        }
        dp[iter] *= 2;
        if(iter%2)
        {
            dp[iter] += dp[iter/2]*dp[iter/2];
        }
    }
    int ans = dp[n];
    free(dp);
    return ans;
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
        long long int ans = sol.uniqueBST(n);
        cout << ans << endl;
    }
    return 0;
}
