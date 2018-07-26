#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int atleatOneZero(vector<int> &A);
};
Solution::Solution(){}
int Solution::atleatOneZero(vector<int> &A)
{
    int len = A.size();
    int *dp = (int *)malloc(sizeof(int) * len);
    dp[0]  = A[0];
    for(int iter = 1; iter < len ;iter++)
    {
        dp[iter] = dp[iter-1] + A[iter];
    }
    for(int iter = 0; iter < len; iter++)
    {
        if(dp[iter] == 0)
        {
            return 1;
        }
        for(int jter = 0; jter < iter; jter++)
        {
            if(dp[iter] - dp[jter] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
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
        int ans = sol.atleatOneZero(v);
        if(ans)
        {
            cout << "Yes" <<endl;
        }
        else
        {
            cout << "No" <<endl;
        }
    }
    return 0;
}
