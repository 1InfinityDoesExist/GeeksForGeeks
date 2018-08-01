
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<vector<int> > transpose(vector<vector<int> > &A);
};
Solution::Solution(){}
 vector<vector<int>> Solution::transpose(vector<vector<int>>& A)
    {
        vector<vector<int> > ans;
        int jter = 0;
        int col = A[0].size();
        while(jter < col)
        {
            vector<int> B;
            int iter = 0;
            while(iter < A.size())
            {
               B.push_back(A[iter][jter]);
                iter++;
            }
            ans.push_back(B);
            jter++;
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
        vector<vector<int> > A;
        for(int iter = 0; iter < n; iter++)
        {
            vector<int> ans;
            for(int jter = 0; jter < n; jter++)
            {
                int data;
                cin >> data;
                ans.push_back(data);
            }
            A.push_back(ans);
        }
        vector<vector<int> > res = sol.transpose(A);
        for(int iter = 0; iter < res.size(); iter++)
        {
            for(int jter = 0; jter < res[iter].size(); jter++)
            {
                cout << res[iter][jter] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
