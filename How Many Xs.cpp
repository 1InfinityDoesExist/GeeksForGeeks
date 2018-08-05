#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int findX(int n, int left, int right);
};
Solution::Solution(){}
int Solution::findX(int n, int left, int right)
{
    int count (0);
    for(int iter = left+1; iter < right; iter++)
    {
        int x = iter;
        while(x > 0)
        {
            int rem = x%10;
            if(rem == n)
            {
                count++;
            }
            x /= 10;
        }
    }
    return count;
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
        int left , right;
        cin >> left >> right;
        int ans = sol.findX(n, left, right);
        cout << ans << endl;
    }
    return 0;
}
