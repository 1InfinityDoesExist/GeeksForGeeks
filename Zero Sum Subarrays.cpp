#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int countZeroContainingSubarray(vector<int> &v);
};
Solution::Solution(){}
int Solution::countZeroContainingSubarray(vector<int> &v)
{
    int n = v.size();
    int count (0);
    int *dp = (int *)malloc(sizeof(int) * v.size());
    dp[0] = v[0];
    for(int iter = 1; iter < v.size(); iter++)
    {
        dp[iter] = dp[iter-1] + v[iter];
    }
    for(int iter = 0; iter < n; iter++)
    {
        if(dp[iter] == 0)
        {
            count++;
        }
        for(int jter = 0; jter < iter; jter++)
        {
            if(dp[iter] - dp[jter] == 0)
            {
                count++;
            }
        }
    }
    return count;
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
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.countZeroContainingSubarray(v);
        cout << ans << endl;
    }
    return 0;
}
