#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int LCS(string str1, string str2);

};
Solution::Solution(){}
int max(int x, int y)
{
    return x > y ? x : y;
}
int Solution::LCS(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    int lcs[n+1][m+1];
    for(int iter = 0; iter <= n; iter++)
    {
        for(int jter = 0; jter <= m; jter++)
        {
            if(iter == 0 || jter == 0)
            {
                lcs[iter][jter] = 0;
            }
            else if(str1[iter-1] == str2[jter-1])
            {
                lcs[iter][jter] = lcs[iter-1][jter-1] +1;
            }
            else
            {
                lcs[iter][jter] = max(lcs[iter-1][jter] , lcs[iter][jter-1]);
            }
        }
    }
    return lcs[n][m];
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
        int ans = sol.LCS(str1, str2);
        cout << ans << endl;
    }
    return 0;
}
