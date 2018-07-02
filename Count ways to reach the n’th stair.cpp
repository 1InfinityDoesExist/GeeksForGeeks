#include<bits/stdc++.h>
using namespace std;

unsigned long long int dp[100001];

class Solution
{
    private:
    public:
        Solution();
        void numberOfStairs();
};
Solution::Solution(){}
void Solution::numberOfStairs()
{
    dp[0] = 1;
    dp[1] = 2;
    for(int iter = 2; iter <= 100001 ; iter++)
    {
        dp[iter] = (dp[iter-1] + dp[iter-2])%1000000007;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    sol.numberOfStairs();
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int data;
        cin >> data;
        cout << dp[data-1] <<endl;
    }

    return 0;
}
