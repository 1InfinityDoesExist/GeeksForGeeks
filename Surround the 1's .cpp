#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maxOnes(vector<vector<int> > &A);
};
Solution::Solution(){}

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool isValid(int x, int y, int row, int col)
{
    if(x < 0 || y < 0 || x >= row || y >= col)
    {
        return false;
    }
    return true;
}
int Solution::maxOnes(vector<vector<int> > &A)
{
    int row = A.size();
    int col = A[0].size();
    if(row == 1 && col == 1)
    {
        return 0;
    }
    int count (0);
    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            if(A[iter][jter] == 1)
            {
                int ct (0);
                for(int kter = 0; kter < 8; kter++)
                {
                    int new_x = iter + dx[kter];
                    int new_y = jter + dy[kter];
                    if(isValid(new_x, new_y, row, col))
                    {
                        if(A[new_x][new_y] == 0)
                        {
                            ct++;
                        }
                    }
                }
                if(ct%2 == 0 && ct > 0)
                {
                    count++;
                }
            }
            else
            {
                continue;
            }
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
        int row, col;
        cin >> row >> col;
        vector<vector<int> > matrix;
        for(int iter = 0; iter < row; iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < col; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            matrix.push_back(temp);
        }
        int ans = sol.maxOnes(matrix);
        cout << ans << endl;
    }
    return 0;
}
