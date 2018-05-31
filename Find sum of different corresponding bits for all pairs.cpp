#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        long long int summation(vector<int> &A);
};
Solution::Solution(){}

long long int Solution::summation(vector<int> &A)
{
    int ans (0);
    int len = A.size();
    for(int iter = 0; iter < 32; iter++)
    {
        int count (0);
        for(int jter = 0; jter < A.size(); jter++)
        {
            if((A[jter] & (1 << iter)))
            {
                count++;
            }
        }
        ans = ans + (count * (len-count)*2);
    }
    return ans%1000000007;
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
        long long int ans = sol.summation(A);
        cout << ans << endl;
    }
    return 0;
}
