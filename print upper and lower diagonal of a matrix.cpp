#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    void printUperNicha(vector<vector<int> > &matrix);
};
Solution::Solution(){}
void Solution::printUperNicha(vector<vector<int> > &matrix)
{
    vector<vector<int> > upper = matrix;
    int row = matrix.size();
    int col = matrix[0].size();
    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            if(iter < jter)
            {
                matrix[iter][jter] = 0;
            }
            cout << matrix[iter][jter] << " ";
        }
        cout << endl;
    }

    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            if(iter > jter)
            {
                upper[iter][jter] = 0;
            }
            cout << upper[iter][jter] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int> > matrix;
    for(int iter = 0; iter < n; iter++)
    {
        vector<int> temp;
        for(int jter = 0; jter < n ;jter++)
        {
            int data;
            cin >> data;
            temp.push_back(data);
        }
        matrix.push_back(temp);
    }
    sol.printUperNicha(matrix);
    return 0;
}

