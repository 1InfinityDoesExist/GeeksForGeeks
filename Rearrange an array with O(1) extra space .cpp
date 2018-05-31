#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> reArrange(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution::reArrange(vector<int> &A)
{
    int len = A.size();
    for(int iter = 0; iter < A.size(); iter++)
    {
        A[iter] = A[iter] + (A[A[iter]]%len)*len;
    }
    for(int iter = 0; iter < A.size(); iter++)
    {
        A[iter] = A[iter]/len;
    }
    return A;
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
        vector<int> A;
        int n;
        cin >> n;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> ans = sol.reArrange(A);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
