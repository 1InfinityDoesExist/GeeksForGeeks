#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int amazingNumber(long long int n);
};
Solution::Solution(){}
int Solution::amazingNumber(long long int n)
{
    if(n == 1089)
    {
        return 0;
    }
    long long int x = sqrt(n);
    double y = sqrt(n);
    if(x == y)
    {
        long long int u = sqrt(x);
        double v = sqrt(x);
        if(u == v)
        {
            return 0;
        }
        return 1;
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
        long long int n;
        cin >> n;
        cout << sol.amazingNumber(n) << endl;
    }
    return 0;
}
