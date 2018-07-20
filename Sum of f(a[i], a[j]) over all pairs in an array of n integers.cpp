#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int sumofji(vector<int> &A);
};
Solution::Solution(){}
int Solution::sumofji(vector<int> &A)
{
    int ans (0);
    for(int iter = 0; iter < A.size(); iter++)
    {
        for(int jter = iter ; jter < A.size(); jter++)
        {
            if(abs(A[jter] - A[iter]) > 1)
            {
                ans += A[jter] - A[iter];
            }
            else
            {
                ans += 0;
            }
        }
    }
    return ans;
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
        int ans = sol.sumofji(A);
        cout << ans << endl;
    }
    return 0;
}
