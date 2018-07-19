#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int matrixIdentical(int **dp1, int **dp2, int n);
};
Solution::Solution(){}
int Solution::matrixIdentical(int **dp1, int **dp2, int n)
{
    for(int iter = 0; iter < n; iter++)
    {
        for(int jter = 0; jter < n; jter++)
        {
            if(dp1[iter][jter] != dp2[iter][jter])
            {
                return 0;
            }
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
        int **dp1 = (int **)malloc(sizeof(int) * n);
        for(int iter = 0; iter < n; iter++)
        {
            dp1[iter] = (int *)malloc(sizeof(int) * n);
        }
        for(int iter = 0; iter < n; iter++)
        {
            for(int jter = 0; jter < n; jter++)
            {
                int data;
                cin >> data;
                dp1[iter][jter] = data;
            }
        }

        int **dp2 = (int **)malloc(sizeof(int) * n);
        for(int iter = 0; iter < n; iter++)
        {
            dp2[iter] = (int *)malloc(sizeof(int) * n);
        }
        for(int iter = 0; iter < n; iter++)
        {
            for(int jter = 0; jter < n; jter++)
            {
                int data;
                cin >> data;
                dp2[iter][jter] = data;
            }
        }

        int ans = sol.matrixIdentical(dp1, dp2, n);
        if(ans)
        {
            cout <<"Yes" <<endl;
        }
        else
        {
            cout << "No" <<endl;
        }
    }
    return 0;
}
