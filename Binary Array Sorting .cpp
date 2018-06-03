#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> binaryArraySorting(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution::binaryArraySorting(vector<int> &A)
{
    sort(A.begin(), A.end());
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
        int n;
        cin >> n;
        vector<int> A;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> ans = sol.binaryArraySorting(A);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter <<" ";
        }
        cout << endl;
    }
    return 0;
}
