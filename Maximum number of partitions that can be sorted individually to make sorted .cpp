#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maxCount(vector<int> &A);
};
Solution::Solution(){}
int min(int x, int y)
{
    return x < y ? x : y;
}
int max(int x, int y)
{
    return x > y ? x : y;
}
int Solution::maxCount(vector<int> &A)
{
    int count (0);
    for(int iter = 0; iter < A.size(); )
    {
        int left = A.size();
        int right = -1;
        for(int jter = iter; jter < A.size(); jter++)
        {
            left = min(left, A[jter]);
            right = max(right, A[jter]);
            if(left == iter && right == jter)
            {
                iter = jter+1;
                count++;
                break;
            }
        }
    }
    return count;
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
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int count = sol.maxCount(v);
        cout << count << endl;
    }
    return 0;
}
