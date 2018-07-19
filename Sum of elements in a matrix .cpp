#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int sumOfMatix(vector<vector<int> > &A);
};
Solution::Solution(){}
int Solution::sumOfMatix(vector<vector<int> > &A)
{
    int row = A.size();
    int col = A[0].size();
    int sum (0);
    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            sum = sum + A[iter][jter];
        }
    }
    return sum;
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
        vector<vector<int> > A;
        for(int iter = 0; iter < row; iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < col; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            A.push_back(temp);
        }
        int ans = sol.sumOfMatix(A);
        cout << ans <<endl;
    }
    return 0;
}
