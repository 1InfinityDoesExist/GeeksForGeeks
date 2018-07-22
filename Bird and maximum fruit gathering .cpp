#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        long long int maxFruit(vector<int> &A, int k);
};
Solution::Solution(){}
long long int Solution::maxFruit(vector<int> &A, int k)
{
    int sum (0);

    int *dp = (int *)malloc(sizeof(int) * A.size());
    int i (0);
    for(vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        sum =  sum + *iter;
        dp[i++] = sum;
    }
    int res;
    if(k >= A.size()) // constraint to be handeled...
    {
        res = dp[A.size()-1];
    }
    else
    {
        res = dp[k-1];
        for(int iter = 1; iter < A.size(); iter++)
        {
            if(iter+k-1 < A.size())
            {
                res = max(res, dp[iter+k-1] - dp[iter-1]);
            }
            else
            {
                res = max(res, dp[(iter+k-1)%A.size()] + dp[A.size()-1]-dp[iter-1]);
            }
        }
    }
    free(dp);
    A.clear();
    return res;
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
        int k;
        cin >> k;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        long long int ans = sol.maxFruit(v, k);
        cout << ans << endl;
    }
    return 0;
}
