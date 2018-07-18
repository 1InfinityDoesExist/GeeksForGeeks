#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int isIsogram(string str);
};
Solution::Solution(){}
int isValid(string str)
{
    string cp = str;
    sort(str.begin(), str.end());
    str.erase(unique(str.begin(), str.end()), str.end());
    if(str.length() == cp.length())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Solution::isIsogram(string str)
{
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
                if(isValid(s) == 0)
                {
                    return 0;
                }
                else
                {
                    s = "";
                }
            }
        }
        else
        {
            s += str[iter];
            if(iter == str.length()-1)
            {
                if(isValid(s) == 0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
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
        int ans = sol.isIsogram(str);
        cout << ans <<endl;
    }
    return 0;
}
