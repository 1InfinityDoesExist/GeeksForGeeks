#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int minJumps(vector<int> &A);
};
Solution::Solution(){}
int Solution::minJumps(vector<int> &A)
{
    if(A[0] == 0)
    {
        return -1;
    }
    int start = 0;
    int end = 0;
    int steps = 0;
    int lastPos = A.size()-1;
    while(end < lastPos)
    {
        steps++;
        int maxEnd = end+1;
        for(int iter = start; iter <= end; iter++)
        {
            if(iter + A[iter] >= lastPos)
            {
                return steps;
            }
            maxEnd = max(maxEnd, iter+A[iter]);
        }
        start = end+1;
        end = maxEnd;
        if(A[end] == 0)
        {
            return -1;
        }
    }
    return steps;
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
        int ans = sol.minJumps(A);
        cout << ans << endl;
    }
    return 0;
}
