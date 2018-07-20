#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int divisibleby8(string n);
};
Solution::Solution(){}
int Solution::divisibleby8(string n)
{
    string temp = "";
    int len = n.size();
    if(n.size() >= 3)
    {
        temp = n[len-3];
        temp += n[len-2];
        temp += n[len-1];
    }
    else
    {
        temp = n;
    }
    int x = stoi(temp);
    if(x%8 == 0)
    {
        return 1;
    }
    return -1;
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
        string n;
        cin >> n;
        int ans = sol.divisibleby8(n);
        cout << ans << endl;
    }
    return 0;
}
