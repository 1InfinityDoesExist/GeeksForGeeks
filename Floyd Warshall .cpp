#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<vector<int> > foyld(vector<vector<int> > &A);
};
Solution::Solution(){}
vector<vector<int> > Solution::foyld(vector<vector<int> > &A)
{
    for(int kter = 0; kter < A.size(); kter++)
    {
        for(int iter = 0; iter < A.size(); iter++)
        {
            for(int jter = 0; jter < A.size(); jter++)
            {
                if(A[iter][kter] + A[kter][jter] < A[iter][jter])
                {
                    A[iter][jter] = A[iter][kter] + A[kter][jter];
                }
            }
        }
    }
    return A;
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
        vector<vector<int> > v;
        for(int iter = 0; iter < n; iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < n; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            v.push_back(temp);
        }
        vector<vector<int> > ans = sol.foyld(v);
        for(int iter = 0; iter < ans.size(); iter++)
        {
            for(int jter = 0; jter < ans[iter].size(); jter++)
            {
                cout << ans[iter][jter] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
