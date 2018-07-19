#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maxMoney(int house, int money);
};
Solution::Solution(){}
int Solution::maxMoney(int house, int money)
{
    if(house%2 == 0)
    {
        return (house/2)*money;
    }
    else
    {
        return (house/2 + 1)*money;
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
        int house, money;
        cin >> house >> money;
        int ans = sol.maxMoney(house, money);
        cout << ans <<endl;
    }
    return 0;
}
