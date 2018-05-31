#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> primeNumber(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution::primeNumber(vector<int> &A)
{
    vector<int> ans;
    int x = A[0];
    int y = A[1];
    int dp[y+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for(int iter = 2 ; iter <= sqrt(y)+1; iter++)
    {
        if(dp[iter] == 0)
        {
            for(int jter = 2*iter; jter <= y; jter = jter+iter)
            {
                dp[jter] = 1;
            }
        }
    }
    for(int iter = x; iter <= y; iter++)
    {
        if(dp[iter] == 0)
        {
            ans.push_back(iter);
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
        vector<int> A;
        for(int iter = 0; iter <2; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> ans = sol.primeNumber(A);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter <<" ";
        }
        cout << endl;
    }
    return 0;
}
