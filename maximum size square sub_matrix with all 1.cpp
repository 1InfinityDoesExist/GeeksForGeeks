/*   #vido tutorials simple and all implementation in one */
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maxSubarrayWithOnes(vector<vector<int> > &A);
};
Solution::Solution(){}
int Solution::maxSubarrayWithOnes(vector<vector<int> > &A)
{

    int max_i, max_j, max_of_S;
    int row = A.size();
    int col = A[0].size();
    int S[row][col];
    for(int iter = 0; iter < row; iter++)
    {
        S[iter][0] = A[iter][0];
    }
    for(int jter = 0; jter < col; jter++)
    {
        S[0][jter] = A[0][jter];
    }
    for(int iter = 1; iter < row; iter++)
    {
        for(int jter = 1; jter < col; jter++)
        {
            if(A[iter][jter] == 1)
            {
                S[iter][jter] = min(min(S[iter-1][jter], S[iter][jter-1]),S[iter-1][jter-1]) + 1;
            }
            else
            {
                S[iter][jter] = 0;
            }
        }
    }


    max_of_S = S[0][0];
    max_i = 0;
    max_j = 0;
    for(int iter = 0; iter < row; iter++)
    {
        for(int jter = 0; jter < col; jter++)
        {
            if(max_of_S < S[iter][jter])
            {
                max_of_S = S[iter][jter];
                max_i = iter;
                max_j = jter;
            }
        }
    }
    int count (0);
    for(int iter = max_i; iter > max_i - max_of_S; iter--)
    {
        count++;
       /* for(int jter = max_j; jter > max_j - max_of_S; jter--)
        {
            cout << A[iter][jter] << " ";
        }
        cout << endl;*/
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
        int row;
        cin >> row;
        int col;
        cin >> col;
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

        int ans = sol.maxSubarrayWithOnes(A);
        cout << ans << endl;
    }
    return 0;
}
