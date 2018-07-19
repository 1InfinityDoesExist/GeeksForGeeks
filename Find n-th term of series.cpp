#include<bits/stdc++.h>
using namespace std;

int dp[1001];
class Solution
{
    private:
    public:
        Solution();
        void calculate();

};
Solution::Solution(){}
void Solution::calculate()
{
    dp[0] = 1;
    for(int iter = 1; iter <= 1001; iter++)
    {
        dp[iter] = dp[iter-1] + iter + 1;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    sol.calculate();
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int data;
        cin >> data;
        cout << dp[data-1] << endl;
    }
    return 0;
}
