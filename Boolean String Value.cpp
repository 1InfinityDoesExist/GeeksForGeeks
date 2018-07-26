#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int booleanStringValue(string str);
};
Solution::Solution(){}
int Solution::booleanStringValue(string str)
{
    stack<char> s;
    int ans;
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == '0' || str[iter] == '1')
        {
            if(s.size() == 0)
            {
                s.push(str[iter]);
            }
            else if(s.top() == '^')
            {
                s.pop();
                int a = s.top() - '0';
                s.pop();
                int b = str[iter] - '0';
                ans = a ^ b;
                s.push(ans + '0');
            }
            else if(s.top() == '|')
            {
                s.pop();
                int a = s.top() - '0';
                s.pop();
                int b = str[iter] - '0';
                ans = a | b;
                s.push(ans + '0');
            }
            else if(s.top() == '&')
            {
                s.pop();
                int a = s.top() - '0';
                s.pop();
                int b = str[iter] - '0';
                ans = a &  b;
                s.push(ans + '0');
            }

        }
        else if(str[iter] >= 'A' && str[iter] <= 'Z')
        {
            if(str[iter] == 'A')
            {
                s.push('&');
            }
            else if(str[iter] == 'B')
            {
                s.push('|');
            }
            else if(str[iter] == 'C')
            {
                s.push('^');
            }

        }
    }
    return ans;
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
        int ans = sol.booleanStringValue(str);
        cout << ans << endl;
    }
    return 0;
}
