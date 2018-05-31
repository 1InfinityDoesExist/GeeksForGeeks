#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int longestValidParenthesis(string str);

};
Solution::Solution(){}
int Solution::longestValidParenthesis(string s)
{
    int longest = 0;
    int n = s.length();
    stack<int> st;
    for(int iter = 0; iter < n; iter++)
    {
        if(s[iter] == '(')
        {
            st.push(iter);
        }
        else
        {
            if(!st.empty())
            {
                if(s[st.top()] == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(iter);
                }
            }
            else
            {
                st.push(iter);
            }
        }
    }

    if(st.empty())
    {
        longest = n;
    }
    else
    {
        int a = n;
        int b = 0;
        while(!st.empty())
        {
            b = st.top();
            st.pop();
            longest = max (longest, a-b-1);
            a = b;
        }
        longest = max(longest, a);
    }
    return longest;
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
        int ans = sol.longestValidParenthesis(str);
        cout << ans << endl;
    }
    return 0;
}
