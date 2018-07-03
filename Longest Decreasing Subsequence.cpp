#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int LDS(vector<int> &A);
};
Solution::Solution(){}
int Solution::LDS(vector<int> &A)
{
    int len = A.size();
    int *dp = (int *)malloc(sizeof(int ) * len);
    for(int iter = 0; iter < len ;iter++)
    {
        dp[iter] = 1;
    }
    for(int iter = len-2; iter >= 0; iter--)
    {
        for(int jter = len-1; jter > iter; jter--)
        {
            if(A[iter] > A[jter] && dp[iter] < dp[jter]+1)
            {
                dp[iter] = dp[jter] + 1;
            }
        }
    }
    int max = INT_MIN;
    for(int iter = 0; iter < len; iter++)
    {
        if(max < dp[iter])
        {
            max = dp[iter];
        }
    }
    return max;
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
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.LDS(v);
        cout << ans << endl;
    }
    return 0;
}
