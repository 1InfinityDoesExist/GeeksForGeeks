#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> solve(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution::solve(vector<int> &A)
{
    vector<int> v;
    v.push_back(1);
    for(vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        v.push_back(v.back() * (*iter));
    }
    int k (1);
    for(int iter = 0; iter < A.size(); iter++)
    {
        v[A.size()-iter-1] = v[A.size()-iter-1] * k;
        k = k * A[A.size()-iter-1];
    }
    v.pop_back();
    return v;
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
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> ans = sol.solve(A);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
