#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        pair<int, int> corner(long long int n);
};
Solution::Solution(){}
pair<int, int> Solution::corner(long long int n)
{
    vector<int> v;
    while(n > 0)
    {
        v.push_back(n%10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    return make_pair(v[0], v[v.size() -1]);
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
        pair<int, int> p = sol.corner(n);
        cout << p.first << " "<<p.second <<endl;
    }
    return 0;
}
