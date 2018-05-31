#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int numberOfRectangles(vector<vector<int> > &A);
};
Solution::Solution(){}
int Solution::numberOfRectangles(vector<vector<int> > &A)
{
    int R = A.size();
    int C = A[0].size();
    int hist[R+1][C+1];

    for(int iter = 0; iter < C; iter++)
    {
        hist[0][iter] = A[0][iter];
        for(int jter = 1; jter < R; jter++)
        {
            hist[jter][iter] = (A[jter][iter] == 0 ? 0 : hist[jter-1][iter] + 1);
        }
    }
    for(int iter = 0; iter < R; iter++)
    {
        int count[R+1] = {0};
        for(int jter = 0; jter < C; jter++)
        {
            count[hist[iter][jter]]++;
        }
        int col_no = 0;
        for(int jter = R; jter >= 0; jter--)
        {
            if(count[jter] > 0)
            {
                for(int kter = 0; kter < count[jter]; kter++)
                {
                    hist[iter][col_no] = jter;
                    col_no++;
                }
            }
        }
    }

    int curr_area, max_area = 0;
    for(int iter = 0; iter < R; iter++)
    {
        for(int jter = 0; jter < C; jter++)
        {
            curr_area = (jter +1)*hist[iter][jter];
            if(curr_area  > max_area)
            {
                max_area = curr_area;
            }
        }
    }
    return max_area;

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
        int ans = sol.numberOfRectangles(A);
        cout << ans << endl;
    }
    return 0;
}
