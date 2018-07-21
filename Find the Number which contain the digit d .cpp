#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void solve(int n, int num);
};
Solution::Solution(){}
bool isValid(int x, int n)
{
    while(x > 0)
    {
        int rem = x%10;
        if(rem == n)
        {
            return true;
        }
        x /= 10;

    }
    return false;
}
void Solution::solve(int n, int num)
{
    vector<int> ans;
    if(num == 0)
    {
        ans.push_back(0);
    }
    bool mila = true;
    for(int iter = 0; iter <= n; iter++)
    {
        if(isValid(iter, num))
        {
            ans.push_back(iter);
        }
    }
    if(ans.size() == 0)
    {
        cout << "-1" <<endl;
    }
    else
    {
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
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
        int n, num;
        cin >> n >> num;
        sol.solve(n ,num);
        cout << endl;
    }
    return 0;
}
