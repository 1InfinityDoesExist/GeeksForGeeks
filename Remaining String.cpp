#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string remainingString(string str, char c, int n);
};
Solution::Solution(){}
string Solution::remainingString(string str, char ch, int n)
{
    int count (0);
    if(n == 0)
    {
        return str;
    }
    string::size_type iter = 0;
    for(; iter < str.length(); iter++)
    {
        if(str[iter] == ch)
        {
            count++;
        }
        if(count == n)
        {
            break;
        }
    }
    if(iter < str.length()-1)
    {
        return str.substr(iter+1, str.length()-(iter+1));
    }
    else
    {
        return "Empty string";
    }
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
        string str;
        cin >> str;
        char c;
        cin >> c;
        int n;
        cin >> n;
        string ans = sol.remainingString(str, c, n);
        cout << ans << endl;
    }
    return 0;
}
