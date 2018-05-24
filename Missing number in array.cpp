#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int missingNumber(vector<int> &A);
};
Solution::Solution(){}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Solution::missingNumber(vector<int> &A)
{
    for(int iter = 0; iter < A.size(); iter++)
    {
        if(A[iter] > 0 && A[iter] <= A.size())
        {
            int pos = A[iter];
            if(A[pos] != A[iter])
            {
                swap(A[pos], A[iter]);
                iter--;
            }
        }
    }
    for(int iter = 1; iter <= A.size(); iter++)
    {
        if(A[iter] != iter)
        {
            return iter;
        }
    }
    return A.size()+1;
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
        for(int iter = 0; iter < n-1; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.missingNumber(A);
        cout << ans <<endl;
    }
    return 0;
}
