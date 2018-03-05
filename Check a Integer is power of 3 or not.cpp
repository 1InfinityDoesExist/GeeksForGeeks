#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int powerof3(const int n);
};
Solution::Solution(){}
int Solution::powerof3(const int n)
{
    if(n <= 0)
    {
        return false;
    }
    unsigned long long int ans = pow(3, 22);
    if(ans%n == 0)
    {
        return true;
    }
    return false;
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
        int ans = sol.powerof3(n);
        if(ans == 1)
        {
            cout << "Yes" <<endl;
        }
        else
        {
            cout << "No" <<endl;
        }
    }
    return 0;
}
