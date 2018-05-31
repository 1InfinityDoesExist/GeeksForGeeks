#include<bits/stdc++.h>
using namespace std;


int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};

bool isValid(int x, int y, int row, int col)
{
    if(x < 0 || y < 0 || x >= row || y >= col)
    {
        return false;
    }
    return true;
}

void bfs(int i, int j , vector<vector<char> > &A)
{
    int row = A.size();
    int col = A[0].size();
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    while(!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        A[temp.first][temp.second] = 'O';
        for(int iter = 0; iter < 4; iter++)
        {
            int x = temp.first + dx[iter];
            int y = temp.second + dy[iter];

            if(isValid(x, y, row, col) && A[x][y] == 'X')
            {
                q.push(make_pair(x, y));
            }
        }
    }
}
class Solution
{
    private:
    public:
        Solution();
        int totalXXX(vector<vector<char> > &A);
};
Solution::Solution(){}
int Solution::totalXXX(vector<vector<char> > &A)
{
    int row = A.size();
    int col = A[0].size();
    int count (0);
    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            if(A[iter][jter] == 'X')
            {
                count++;
                bfs(iter, jter, A);
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
        vector<vector<char> > A;
        int row, col;
        cin >> row >> col;
        for(int iter = 0; iter < row; iter++)
        {
            vector<char> temp;
            for(int jter = 0; jter < col; jter++)
            {
                char ch;
                cin >> ch;
                temp.push_back(ch);
            }
            A.push_back(temp);
        }
        int ans = sol.totalXXX(A);
        cout << ans << endl;
    }
    return 0;
}
