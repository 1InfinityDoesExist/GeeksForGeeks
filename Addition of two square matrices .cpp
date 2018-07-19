#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<vector<int> > addMatrix(vector<vector<int> > &A, vector<vector<int> > &B);
};
Solution::Solution(){}
vector<vector<int> > Solution::addMatrix(vector<vector<int> > &A, vector<vector<int> > &B)
{
    vector<vector<int> > ans;
    for(int iter = 0; iter < A.size(); iter++)
    {
        vector<int> temp;
        for(int jter = 0; jter < B.size(); jter++)
        {
            temp.push_back(A[iter][jter] + B[iter][jter]);
        }
        ans.push_back(temp);
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

        vector<vector<int> > u;
        for(int iter = 0; iter < n; iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < n; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            u.push_back(temp);
        }
        vector<vector<int> > ans = sol.addMatrix(v, u);
        for(int iter = 0; iter < n ;iter++)
        {
            for(int jter = 0; jter < n; jter++)
            {
                cout << ans[iter][jter] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
