#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maxWeight(string str1, string str2);
};
Solution::Solution(){}
int position(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return (c - 'a') + 1;
    }
    else if(c >= 'A' && c <= 'Z')
    {
        return (c - 'A') + 1;
    }
    else
    {
        return -1;
    }
}
int Solution::maxWeight(string str1, string str2)
{
    int weight1 (0);
    int weight2 (0);
    for(string::size_type iter = 0; iter < str1.length(); iter++)
    {
         weight1 += position(str1[iter]);
    }
    for(string::size_type iter = 0; iter < str2.length(); iter++)
    {
        weight2 += position(str2[iter]);
    }
    if(weight1 > weight2)
    {
        return 1;
    }
    else if(weight1 < weight2)
    {
        return 2;
    }
    else
    {
        return 3;
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
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        int ans = sol.maxWeight(str1, str2);
        if(ans == 3)
        {
            cout << "equal" <<endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
