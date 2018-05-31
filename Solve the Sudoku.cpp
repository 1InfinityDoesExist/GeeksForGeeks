#include<bits/stdc++.h>
using namespace std;

int rowHash[9][9];
int colHash[9][9];
int boardHash[3][3][9];
class Solution
{
    private:
    public:
        Solution();
        void solveSudoku(vector<vector<char> > &A);
};
Solution::Solution(){}
bool solveSuduko(vector<vector<char> > &A, int pos)
{
    if(pos >= 9*9)
    {
        return true;
    }
    int row = pos/9;
    int col = pos%9;
    if(A[row][col] != '0')
    {
        return solveSuduko(A, pos+1);
    }
    for(int num = 0; num < 9; num++)
    {
        if(rowHash[row][num] != 1 && colHash[col][num] != 1 && boardHash[row/3][col/3][num] != 1)
        {
            A[row][col] = num + '1';
            rowHash[row][num] = 1;
            colHash[col][num] = 1;
            boardHash[row/3][col/3][num] = 1;
            if(solveSuduko(A, pos+1))
            {
                return true;
            }
            A[row][col] = '0';
            rowHash[row][num] = 0;
            colHash[col][num] = 0;
            boardHash[row/3][col/3][num] = 0;
        }
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char> >& A)
{
    memset(rowHash, 0, sizeof(rowHash));
    memset(colHash, 0, sizeof(colHash));
    memset(boardHash, 0, sizeof(boardHash));
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            if(A[row][col] != '0')
            {
                int num = A[row][col] - '1';
                rowHash[row][num] = 1;
                colHash[col][num] = 1;
                boardHash[row/3][col/3][num] = 1;
            }
        }
    }
    solveSuduko(A, 0);
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
        for(int iter = 0; iter < 9; iter++)
        {
            vector<char> temp;
            for(int jter = 0; jter < 9; jter++)
            {
                char data;
                cin >> data;
                temp.push_back(data);
            }
            A.push_back(temp);
        }
        sol.solveSudoku(A);
        for(int iter = 0; iter < 9; iter++)
        {
            for(int jter = 0; jter < 9; jter++)
            {
                cout << A[iter][jter] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
