#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int checkforSubsequence(string str1, string str2);
};
Solution::Solution(){}
int Solution::checkforSubsequence(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int jter (0);
    for(string::size_type iter = 0; iter < len2; iter++)
    {
        if(str1[jter] == str2[iter])
        {
            if(jter == str1.length()-1)
            {
                return 1;
            }
            jter++;

        }
        else
        {
            continue;
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
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        int ans = sol.checkforSubsequence(str1, str2);
        cout << ans << endl;
    }
    return 0;
}
