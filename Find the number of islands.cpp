Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*you are required to complete this method*/
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0 ,0, 1 ,-1, 1 , -1, -1, 1};
bool isValid(int x, int y, int M, int N)
{
    if(x < 0 || y < 0 || x >= M || y >= N)
    {
        return false;
    }
    return true;
}
void bfs(int iter , int jter, vector<vector<int> > &R)
{
    int row = R.size();
    int col = R[0].size();
    queue<pair<int, int> > q;
    q.push(make_pair(iter, jter));
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        R[x][y] = 0;
        for(int iter = 0; iter < 8; iter++)
        {
            int new_x = x + dx[iter];
            int new_y = y + dy[iter];
            if(isValid(new_x, new_y, row, col) && R[new_x][new_y] != 0)
            {
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}
int findIslands(int A[MAX][MAX], int N, int M)
{
//Your code here
    vector<vector<int> > vec;
    for(int iter = 0; iter < N; iter++)
    {
        vector<int> temp;
        for(int jter = 0; jter < M; jter++)
        {
            temp.push_back(A[iter][jter]);
        }
        vec.push_back(temp);
    }

    int count (0);
    for(int iter = 0; iter < vec.size(); iter++)
    {
        for(int jter = 0; jter < vec[iter].size(); jter++)
        {
            if(vec[iter][jter] == 1)
            {
                count++;
                bfs(iter, jter, vec);
            }
        }
    }
    return count;
}
