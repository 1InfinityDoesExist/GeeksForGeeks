#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        vector<char> v;
    public:
        Solution();
        string removeConsonant(string str);
        string removeConst(string str);
};
Solution::Solution()
{
    v.push_back('a');v.push_back('A');
    v.push_back('e');v.push_back('E');
    v.push_back('i');v.push_back('I');
    v.push_back('o');v.push_back('O');
    v.push_back('u');v.push_back('U');
}
string Solution::removeConst(string str)
{
    string s = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(isalpha(str[iter]))
        {
            if(find(v.begin(), v.end(), str[iter]) != v.end())
            {
                s += str[iter];
            }
        }
    }
    return s;
}
string Solution::removeConsonant(string str)
{
    string s = "";
    queue<string> st;
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
                st.push(removeConst(s));
                s = "";
            }
        }
        else
        {
            s = s + str[iter];
            if(iter == str.length()-1)
            {
                st.push(removeConst(s));
                break;
            }
        }
    }
    str = "";
    while(!st.empty())
    {
        if(st.size() == 1)
        {
            str += st.front();
            break;
        }
        str += st.front();
        str += ' ';
        st.pop();
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
        string ans = sol.removeConsonant(str);
        if(ans.length() == 0)
        {
            cout << "No Vowel" <<endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
