#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<vector<int> > solve(vector<vector<int> > &A);
};
Solution::Solution(){}
bool isValid(int x, int y, int row, int col)
{
    if(x < 0 || y < 0 || x >= row || y >= col)
    {
        return false;
    }
    return true;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector<vector<int> > Solution::solve(vector<vector<int> > &A)
{
    int row = A.size();
    int col = A[0].size();

    vector<vector<int> > v = A;
    for(int kter = 0; kter < row; kter++)
    {
        for(int iter = 0; iter < row; iter++)
        {
            for(int jter = 0; jter < col; jter++)
            {
                if(iter == jter)
                {
                    v[iter][jter] = 1;
                    continue;
                }
                v[iter][jter] = v[iter][jter] || (v[iter][kter] && v[kter][jter]);
            }
        }
    }
    return v;
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
        vector<vector<int> > V;
        for(int iter = 0; iter < n; iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < n; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            V.push_back(temp);
        }
        vector<vector<int> > ans = sol.solve(V);
        for(int iter = 0; iter < n; iter++)
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
