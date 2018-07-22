#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int LCSofThreeString(string str1, string str2, string str3);
};
Solution::Solution(){}
int max(int x, int y)
{
    return x > y ? x : y;
}
int Solution::LCSofThreeString(string str1, string str2, string str3)
{
    //cout << str1 << " "<< str2 << " "<<str3;
    int len1 = str1.length();
    int len2 = str2.length();
    int len3 = str3.length();
    int dp[len1+1][len2+1][len3+1];
    for(int iter = 0; iter <= len1; iter++)
    {
        for(int jter = 0; jter <= len2; jter++)
        {
            for(int kter = 0; kter <= len3; kter++)
            {
                if(iter == 0 || jter == 0|| kter ==0)
                {
                    dp[iter][jter][kter] = 0;
                }
                else if(str1[iter-1] == str2[jter-1] && str1[iter-1] == str3[kter-1])
                {
                    dp[iter][jter][kter] = 1+ dp[iter-1][jter-1][kter-1];
                }
                else
                {
                    dp[iter][jter][kter] = max(max(dp[iter-1][jter][kter], dp[iter][jter-1][kter]), dp[iter][jter][kter-1]);
                }
            }
        }
    }
    return dp[len1][len2][len3];
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
        int m , n, l;
        cin >> m >> n >> l;
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;

        int ans = sol.LCSofThreeString(str1, str2, str3);
        cout << ans << endl;
    }
    return 0;
}
