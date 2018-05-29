#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int singleElement(vector<int> &A);
};
Solution::Solution(){}
int Solution::singleElement(vector<int> &A)
{
    int iter (0);
    for(; iter < A.size(); iter++)
    {
        if(A[iter] != A[++iter])
        {
            return A[--iter];
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
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.singleElement(A);
        cout << ans << endl;
    }
    return 0;
}
