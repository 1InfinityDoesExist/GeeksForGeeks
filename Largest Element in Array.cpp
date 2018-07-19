#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int largestNumber(vector<int> &A);
};
Solution::Solution(){}
int Solution::largestNumber(vector<int> &A)
{
    sort(A.begin(), A.end(), greater<int>());
    return A[0];
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
        int ans = sol.largestNumber(v);
        cout << ans <<endl;
    }
    return 0;
}
