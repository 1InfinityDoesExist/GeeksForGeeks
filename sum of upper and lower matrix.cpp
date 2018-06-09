#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    pair<int, int> triangleSum(vector<vector<int> > &matrix);

};
Solution::Solution(){}
pair<int, int> Solution::triangleSum(vector<vector<int> > &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int upperSum (0);
    int lowerSum (0);

    //Adding for upper sum

    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            upperSum += matrix[iter][jter];
        }
    }
    //Adding for lower sum
    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            if(iter <= jter)
            {
                lowerSum += matrix[iter][jter];
            }
        }
    }
    pair<int, int> res = make_pair(lowerSum, upperSum);
    return res;
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
        pair<int, int> ans = sol.triangleSum(matrix);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
