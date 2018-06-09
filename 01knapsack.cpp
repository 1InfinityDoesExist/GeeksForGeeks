#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int maxProfit(int W, vector<int> &wt, vector<int> &val);
};
int max(int x, int y)
{
    return x > y ? x : y;
}
Solution::Solution(){}
int Solution::maxProfit(int W, vector<int> &wt, vector<int> &val)
{
    int n = wt.size();

    int table[n+1][W+1];

    for(int iter = 0; iter <= n; iter++)
    {
        for(int w = 0; w <= W ; w++)
        {
            if(iter == 0 || w == 0)
            {
                table[iter][w] = 0;
            }
            else if(wt[iter-1] <= w )
            {
                table[iter][w] = max(val[iter-1] + table[iter-1][w-wt[iter-1]], table[iter-1][w]);
            }
            else
            {
                table[iter][w] = table[iter-1][w];
            }
        }
    }

    return table[n][W];
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
         vector<int> val;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            val.push_back(data);
        }
        vector<int> wt;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            wt.push_back(data);
        }


        int ans = sol.maxProfit(W, wt, val);
        cout << ans << endl;
    }
    return 0;
}
