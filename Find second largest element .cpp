#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int secondLargestNumber(vector<int> &A);
};
Solution::Solution(){}
int Solution::secondLargestNumber(vector<int> &A)
{
    if(A.size() < 2)
    {
        return -1;
    }

    sort(A.begin(), A.end(), greater<int>());
    A.erase(unique(A.begin(), A.end()), A.end());
    if(A.size() == 1)
    {
        return -1;
    }
    return A[1];
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
        int ans = sol.secondLargestNumber(v);
        cout << ans << endl;
    }
    return 0;
}
