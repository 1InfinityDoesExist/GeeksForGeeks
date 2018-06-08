#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
   int numDistinct(string S, string T);
};
Solution::Solution(){}
 int Solution::numDistinct(string S, string T)
{

    int len_S = S.length();
    int len_T = T.length();

   // vector<vector<int> > dp(len_S+1, vector<int>(len_T+1, 0));
   int **dp = (int **)malloc(sizeof(int) * len_S+1);
   for(int iter = 0; iter <= len_T; iter++)
   {
       dp[iter] = (int *)malloc(sizeof(int) * len_T+1);
   }
   for(int iter = 0; iter <= len_S; iter++)
   {
       for(int jter = 0; jter <= len_T; jter++)
       {
           dp[iter][jter] = 0;
       }
   }
    for(int iter = 0; iter <= len_S; iter++)
    {
        dp[iter][0] = 1;
    }

    for(int iter = 1; iter <= len_S; iter++)
    {
        for(int jter = 1; jter <= len_T; jter++)
        {
            if(S[iter-1] == T[jter-1])
            {
                dp[iter][jter] = dp[iter][jter] + dp[iter-1][jter] + dp[iter-1][jter-1];
            }
            else
            {
                dp[iter][jter] += dp[iter-1][jter];
            }
        }
    }
   return dp[len_S][len_T];
}
int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;

    string str1;
    cin >> str1;
    string str2;
    cin >> str2;

    int ans = sol.numDistinct(str1 , str2);
    cout << ans <<endl;
    return 0;
}
