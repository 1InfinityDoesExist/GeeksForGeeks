#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int *solve(vector<int> &A, const int x);

};
Solution::Solution(){}
int *Solution::solve(vector<int> &A, const int x){
    int n = A.size();
    int *ans = (int *)malloc(sizeof(int )*n);
    map<int, int> mp;
    for(int iter = 0; iter < n; iter++)
    {
        if(mp.find(A[iter]) == mp.end())
        {
            int avg = (x+A[iter])/2;
            if(find(A.begin(), A.end(), avg) != A.end())
            {
                mp[A[iter]] = count(A.begin(), A.end(), avg);
            }
        }
    }
    for(int iter = 0; iter < A.size(); iter++)
    {
        ans[iter] = mp[A[iter]];
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
        int x;
        cin >> x;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int *ans = sol.solve(v, x);
        for(int iter = 0; iter < n; iter++)
        {
            cout << ans[iter] << " ";
        }
        cout << endl;
    }
    return 0;
}
