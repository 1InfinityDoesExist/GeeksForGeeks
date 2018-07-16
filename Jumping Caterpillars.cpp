#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int catterpiller(const int N, vector<int> &A);
};
Solution::Solution(){}
int Solution::catterpiller(const int N, vector<int> &A)
{
    bool *p = new bool[N+1];
    for(int iter = 0; iter <= N; iter++)
    {
        p[iter] = true;
    }
    for(int iter = 0; iter < A.size(); iter++)
    {
        int k = A[iter];
        for(int jter = k; jter <= N; jter = jter+k)
        {
            p[jter] = false;

        }
    }
    int count (0);
    for(int iter = 1; iter <= N; iter++)
    {
        if(p[iter] == true)
        {
            count++;
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
        int N;
        cin >> N;
        int n;
        cin >> n;
        vector<int> V;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            V.push_back(data);
        }
        int ans = sol.catterpiller(N, V);
        cout << ans <<endl;
    }
    return 0;
}
