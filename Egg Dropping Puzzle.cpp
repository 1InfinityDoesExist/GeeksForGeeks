#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int eggDropping(int egg, int flor);
};
Solution::Solution(){}
int Solution::eggDropping(int egg, int flor)
{
    int res (0);
    int dp[egg+1][flor+1];
    for(int iter = 1; iter <= egg; iter++)
    {
        dp[iter][0] = 0;
        dp[iter][1] = 1;
    }
    for(int iter = 1; iter <= flor; iter++)
    {
        dp[1][iter] = iter;
    }
    for(int iter = 2; iter <= egg; iter++)
    {
        for(int jter = 2; jter <= flor; jter++)
        {
            dp[iter][jter] = INT_MAX;
            for(int x = 1; x <= jter; x++)
            {
                res = 1 + max(dp[iter-1][x-1], dp[iter][jter-x]);
                if(res < dp[iter][jter])
                {
                   dp[iter][jter] = res;
                }
            }
        }
    }
    return dp[egg][flor];
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
        int egg, flor;
        cin >> egg >> flor;
        int ans = sol.eggDropping(egg, flor);
        cout << ans <<endl;
    }
    return 0;
}
