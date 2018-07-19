#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void isPalindromeOrNot(string str);
};
Solution::Solution(){}
void Solution::isPalindromeOrNot(string str)
{
    string cp = str;
    reverse(str.begin(), str.end());
    if(cp == str)
    {
        cout << "Yes" <<endl;
    }
    else
    {
        cout << "No" <<endl;
    }
    return;
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
        int n;
        cin >> n;
        string str;
        cin >> str;
        sol.isPalindromeOrNot(str);
    }
    return 0;
}
