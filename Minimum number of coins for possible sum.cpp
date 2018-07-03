#include<bits/stdc++.h>
using namespace std;


class Solution
{
    private:
    public:
        Solution();
        int minCoins(int amount, vector<int> &coins);
};
Solution::Solution(){}
int Solution::minCoins(int amount, vector<int> &coins)
{
    sort(coins.begin(), coins.end());
    vector<int> ans;
    for(int iter = coins.size()-1; iter >= 0; iter--)
    {
        while(amount >= coins[iter])
        {
            amount = amount - coins[iter];
            ans.push_back(coins[iter]);
        }
    }
    return ans.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    int amount;
    cin >> amount;
    vector<int> v;
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        v.push_back(data);
    }

    int ans = sol.minCoins(amount, v);
    cout << ans <<endl;
    return 0;
}
