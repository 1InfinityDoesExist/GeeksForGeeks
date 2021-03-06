#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int knapsack(int n, int W, vector<int> &val, vector<int> &wt);
};
Solution::Solution(){}
int Solution::knapsack(int n, int W, vector<int> &val, vector<int> &wt)
{
    int dp[n+1][W+1];
    for(int iter = 0; iter <= n ; iter++)
    {
        for(int w = 0; w <= W; w++)
        {
            if(iter == 0 || w == 0)
            {
                dp[iter][w] = 0;
            }
            else if(wt[iter-1] <= w)
            {
                dp[iter][w] = max(val[iter-1]+dp[iter-1][w - wt[iter-1]], dp[iter-1][w]);
            }
            else
            {
                dp[iter][w] = dp[iter-1][w];
            }
        }
    }
    return dp[n][W];
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
        int W;
        cin >> W;
        vector<int> values;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            values.push_back(data);
        }
        vector<int> weight;
        for(int iter = 0; iter < n ; iter++)
        {
            int data;
            cin >> data;
            weight.push_back(data);
        }
        int ans = sol.knapsack(n, W, values, weight);
        cout  << ans <<endl;
    }
    return 0;
}
