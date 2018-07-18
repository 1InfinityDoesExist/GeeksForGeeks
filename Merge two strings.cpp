#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string merge(string str1, string str2);
};
Solution::Solution(){}
string Solution::merge(string str1, string str2)
{
    string s = "";
    int len1 = str1.length();
    int len2 = str2.length();
    int iter = 0;
    int jter = 0;
    while(iter < len1 && iter < len2)
    {
        s += str1[iter];
        s += str2[jter];
        iter++;
        jter++;

    }

    while(iter < len1)
    {
        s += str1[iter];
        iter++;
    }
    while(jter < len2)
    {
        s += str2[jter];
        jter++;
    }

    return s;
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
        string ans = sol.merge(str1, str2);
        cout << ans << endl;
    }
    return 0;
}
