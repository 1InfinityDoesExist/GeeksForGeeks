#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int LCSubstring(string str1, string str2);
};
int max(int x, int y)
{
    return x > y ? x : y;
}
Solution::Solution(){}
int Solution::LCSubstring(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int dp[len1+1][len2+1];
    int len = 0;
    for(int iter = 0; iter <= len1; iter++)
    {
        for(int jter = 0; jter <= len2; jter++)
        {
            if(iter == 0 || jter == 0)
            {
                dp[iter][jter] = 0;
            }
            else if(str1[iter-1] == str2[jter-1])
            {
                dp[iter][jter] = dp[iter-1][jter-1] + 1;
                len = max(len, dp[iter][jter]);
            }
            else{
                dp[iter][jter] = 0;
            }
        }
    }
    return len;
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
        int n, m;
        cin >> n >> m;
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        int ans = sol.LCSubstring(str1, str2);
        cout << ans << endl;
    }
    return 0;
}
