#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string url(string str, int n);
};
Solution::Solution(){}
string Solution::url(string str, int n)
{
    int len = str.length();
    queue<string> q;
    string s = "";
    for(string::size_type iter = 0; iter < len; iter++)
    {
        if(str[iter] == ' ')
        {
            if(s.length() == 0)
            {
                continue;
            }
            else
            {
                q.push(s);
                s = "";
            }
        }
        else
        {
            s = s + str[iter];
            if(iter == str.length()-1)
            {
                q.push(s);
            }
        }
    }
    str = "";
    while(!q.empty())
    {
        if(q.size() == 1)
        {
            str += q.front();
            q.pop();
            return str;
        }
        str += q.front();
        q.pop();
        str += "%20";
    }
    return str;
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
        int n;
        cin >> n;
        cin.ignore();
        string ans = sol.url(str, n);
        cout << ans <<endl;
    }
    return 0;
}
