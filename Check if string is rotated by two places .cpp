#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int check(string str, string s);
};
Solution::Solution(){}
int Solution::check(string str, string s)
{
    string scpy = s;
    for(int iter = 0; iter < 2; iter++)
    {
        rotate(scpy.begin(), scpy.begin()+1, scpy.end());
        if(scpy == str)
        {
            return 1;
        }
    }
    string sp = s;
    for(int iter = 0; iter < 2; iter++)
    {
        rotate(sp.rbegin(), sp.rbegin()+1, sp.rend());
        if(sp == str)
        {
            return 1;
        }
    }
    return 0;
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
        string str1, str2;
        cin >> str1 >> str2;
        int ans = sol.check(str1, str2);
        cout << ans <<endl;
    }
    return 0;
}
