#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int releventOrNot(vector<int> &A, vector<int> &B);
};
Solution::Solution(){}
int Solution::releventOrNot(vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int iter = 0; iter < A.size() ;iter++)
    {
        if(A[iter] > B[iter])
        {
            return 0;
        }
    }
    return 1;
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
        vector<int> B;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        for(int jter = 0; jter < n; jter++)
        {
            int data;
            cin >> data;
            B.push_back(data);
        }
        int ans = sol.releventOrNot(A, B);
        if(ans == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
