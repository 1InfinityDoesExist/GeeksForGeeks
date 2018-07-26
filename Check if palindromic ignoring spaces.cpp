#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int spacewalapalindrome(string str);
};
Solution::Solution(){}
int Solution::spacewalapalindrome(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    int start (0);
    int end = str.length()-1;
    while(start < end)
    {
        if(str[start++] != str[end--])
        {
            return false;
        }
    }
    return true;
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
        int ans = sol.spacewalapalindrome(str);
        if(ans)
        {
            cout << "YES" <<endl;
        }
        else
        {
            cout << "NO" <<endl;
        }
    }
    return 0;
}
