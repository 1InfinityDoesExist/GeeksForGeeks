#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maximumIndex(vector<int> &A);
};
Solution::Solution(){}
int Solution::maximumIndex(vector<int> &A)
{
    int len = A.size();
    int *leftMin = (int *)malloc(sizeof(int) * len);
    leftMin[0] = A[0];
    for(int iter = 1; iter < len; iter++)
    {
        leftMin[iter] = min(A[iter], leftMin[iter-1]);
    }

    int *rightMax = (int *)malloc(sizeof(int) * len);
    rightMax[len-1] = A[len-1];
    for(int iter = len-2; iter >= 0; iter--)
    {
        rightMax[iter] = max(A[iter], rightMax[iter+1]);
    }
    int iter (0);
    int jter (0);
    int maxDiff (-99999);
    while(iter < len && jter < len)
    {
        if(leftMin[iter] <= rightMax[jter])
        {
            maxDiff = max(maxDiff, jter-iter);
            jter++;
        }
        else
        {
            iter++;
        }
    }
    return maxDiff;
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
        int ans = sol.maximumIndex(v);
        if(ans == -99999)
        {
            cout << '0' << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}
