#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int longestBitonicSubSequence(vector<int> A);
};
Solution::Solution(){}
int Solution::longestBitonicSubSequence(vector<int> A)
{
    int n = A.size();

    int *temp1 = (int *)malloc(sizeof(int) * n);
    for(int iter = 0; iter < n; iter++)
    {
        temp1[iter] = 1;
    }
    for(int iter = 1; iter < n; iter++)
    {
        for(int jter = 0; jter < iter; jter++)
        {
            if(A[iter] > A[jter] && temp1[iter] < temp1[jter]+1)
            {
                temp1[iter] = temp1[jter] + 1;
            }
        }
    }

    int *temp2 = (int *)malloc(sizeof(int) * n);
    for(int iter = 0; iter < n; iter++)
    {
        temp2[iter] = 1;
    }

    for(int iter = n-2; iter >= 0; iter--)
    {
        for(int jter = n-1; jter > iter; jter--)
        {
            if(A[iter] > A[jter] && temp2[iter] < temp2[jter]+1)
            {
                temp2[iter] = temp2[jter] + 1;
            }
        }
    }

    int mx = temp1[0] + temp2[0] -1;
    for(int iter = 1; iter < n ;iter++)
    {
        if(temp1[iter] + temp2[iter] -1 > mx)
        {
            mx = temp1[iter] + temp2[iter] -1;
        }
    }
    free(temp1);
    free(temp2);
    return mx;
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

        int ans = sol.longestBitonicSubSequence(v);
        cout << ans << endl;
    }
    return 0;
}
