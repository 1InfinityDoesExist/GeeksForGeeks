#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int oddNumber(vector<int> &A);
};
Solution::Solution(){}
int Solution::oddNumber(vector<int> &A)
{
    int res (0);
    for(int iter = 0; iter < A.size(); iter++)
    {
        res = res ^ A[iter];
    }
    return res;
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
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.oddNumber(v);
        cout << ans << endl;
    }
    return 0;
}
