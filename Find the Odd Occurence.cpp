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
    map<int, int> mp;
    for(int iter = 0; iter < A.size(); iter++)
    {
        mp[A[iter]]++;
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int iter = 0; iter < A.size(); iter++)
    {
        if(mp[A[iter]]%2 != 0)
        {
            return A[iter];
        }
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
