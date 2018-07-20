#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string commonChar(string str1, string str2);
};
Solution::Solution(){}
string Solution::commonChar(string str1, string str2)
{
    sort(str1.begin(), str1.end());
    str1.erase(unique(str1.begin(), str1.end()), str1.end());
    sort(str2.begin(), str2.end());
    str2.erase(unique(str2.begin(), str2.end()), str2.end());
    map<char, int> mp;
    for(int iter = 0; iter < str1.length(); iter++)
    {
        mp[str1[iter]]++;
    }
    for(int iter = 0; iter < str2.length(); iter++)
    {
        mp[str2[iter]]++;
    }
    string str = "";
    for(map<char, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(iter->second == 2)
        {
            str += iter->first;
        }
    }
    if(str.length() != 0)
    {
        return str;
    }
    return "nil";
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
        string ans = sol.commonChar(str1, str2);
        cout << ans << endl;
    }
    return 0;
}
