#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int LIS(vector<int> &A);
};
Solution::Solution(){}
int Solution::LIS(vector<int> &A)
{
    int max = 0;
    int n = A.size();
    int *temp = (int *)malloc(sizeof(int) * n);
    for(int iter = 0; iter < n; iter++)
    {
        temp[iter] = 1;
    }
    for(int iter = 1; iter < n ;iter++)
    {
        for(int jter = 0; jter < iter; jter++)
        {
            if(A[iter] > A[jter] && temp[iter] < temp[jter] +1)
            {
                temp[iter] = temp[jter]+1;
            }
        }
    }
    for(int iter = 0; iter < n ;iter++)
    {
        if(max < temp[iter])
        {
            max = temp[iter];
        }
    }
    free(temp);
    return max;

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
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.LIS(v);
        cout << ans << endl;
    }
    return 0;
}
