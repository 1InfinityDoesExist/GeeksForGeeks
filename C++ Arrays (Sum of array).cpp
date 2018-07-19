#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int summation(vector<int> &A);
};
Solution::Solution(){}
int Solution::summation(vector<int> &A)
{
    return accumulate(A.begin(), A.end(), 0);
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
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int sum = sol.summation(v);
        cout << sum << endl;
    }
    return 0;
}
