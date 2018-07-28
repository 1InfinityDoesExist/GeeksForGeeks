#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        long long int romanToDecimal(string str);
};
Solution::Solution(){}
long long int Solution::romanToDecimal(string str)
{
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    long long int sum = 0;
    for(string::size_type iter = 0; iter < str.length()-1; iter++)
    {
        if(mp[str[iter]] >= mp[str[iter+1]])
        {
            sum = sum + mp[str[iter]];
        }
        else
        {
            sum = sum - mp[str[iter]];
        }
    }
    sum = sum + mp[str[str.length()-1]];
    return sum;
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
        long long int ans = sol.romanToDecimal(str);
        cout << ans << endl;
    }
    return 0;
}
