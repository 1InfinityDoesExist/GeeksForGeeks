#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string reverseVowel(string str);
};
Solution::Solution(){}
string Solution::reverseVowel(string str)
{
    map<char, int> mp;
    mp['a'] = 1;mp['A'] = 1;
    mp['e'] = 1;mp['E'] = 1;
    mp['i'] = 1;mp['I'] = 1;
    mp['o'] = 1;mp['O'] = 1;
    mp['u'] = 1;mp['U'] = 1;

    string s = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(mp.find(str[iter]) != mp.end())
        {
            s += str[iter];
            str[iter] = '~';
        }
        else
        {
            continue;
        }
    }

    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == '~')
        {
            str[iter] = s.back();
            s.pop_back();
        }
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
        string ans = sol.reverseVowel(str);
        cout << ans <<endl;
    }
    return 0;
}
