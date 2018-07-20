#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maxWordLength(string str);
};
Solution::Solution(){}
int max(int x, int y)
{
    return x > y ? x : y;
}
int Solution::maxWordLength(string str)
{
    int mx = INT_MIN;
    string s = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == ' ')
        {
            if(s.length() == 0)
            {
                continue;
            }
            else
            {
                mx = max(mx, s.length());
                s = "";
            }
        }
        else
        {
            s += str[iter];
            if(iter == str.length()-1)
            {
                mx = max(mx, s.length());
            }
        }
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    cin.ignore();
    while(testCase--)
    {
        string str;
        getline(cin, str);
        int ans = sol.maxWordLength(str);
        cout << ans << endl;
    }
    return 0;
}
