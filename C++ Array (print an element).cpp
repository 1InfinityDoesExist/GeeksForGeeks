#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int valueAtIndex(vector<int> &A, const int index);
};
Solution::Solution(){}
int Solution::valueAtIndex(vector<int> &A, const int index)
{
    return A[index];
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
        int index;
        cin >> index;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.valueAtIndex(v, index);
        cout << ans <<endl;
    }
    return 0;
}
