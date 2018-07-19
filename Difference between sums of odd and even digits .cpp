#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int oddevendiff(long long int x);
};
Solution::Solution(){}
int Solution::oddevendiff(long long int x)
{
    vector<int> v;
    while(x > 0)
    {
        v.push_back(x%10);
        x /= 10;
    }
    int oddSum (0);
    int evenSum (0);
    for(int iter = 0; iter < v.size(); iter++)
    {
        if(iter%2 == 0)
        {
            oddSum += v[iter];
        }
        else
        {
            evenSum += v[iter];
        }
    }
    return (abs(evenSum-oddSum) == 0 ? 1 : 0);
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
        int ans = sol.oddevendiff(n);
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
