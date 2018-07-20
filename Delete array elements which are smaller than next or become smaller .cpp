#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> remover(vector<int> &v, int k);
};
Solution::Solution(){}
vector<int> Solution::remover(vector<int> &A, int k)
{
    int len = A.size();
    int count (0);
    bool mila = false;
    for(int iter = 1; iter < A.size(); iter++)
    {
        for(int jter = iter-1; jter >= 0; jter--)
        {
            if(A[jter] < A[iter] && A[jter] != -9999)
            {
                A[jter] = -9999;
                count++;
                if(count == k)
                {
                    mila = true;
                    break;
                }
            }
        }
        if(mila)
        {
            break;
        }
    }
    vector<int> ans;
    for(int iter = 0; iter < A.size(); iter++)
    {
        if(A[iter] != -9999)
        {
            ans.push_back(A[iter]);
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
        int n;
        cin >> n;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int k;
        cin >> k;
        vector<int> ans = sol.remover(v,k);
        for(int iter = 0; iter < ans.size(); iter++)
        {
            cout << ans[iter] << " ";
        }
        cout << endl;
    }
    return 0;
}
