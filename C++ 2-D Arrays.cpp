#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<vector<int> > makeZeros(vector<vector<int> > &A);
};
Solution::Solution(){}
vector<vector<int> > Solution::makeZeros(vector<vector<int> > &A)
{
    int row = A.size();
    int col = A[0].size();
    bool hasFirstRowZero = false;
    bool hasFirstColZero = false;


    for(int iter = 0; iter < col; iter++)
    {
        if(A[iter][0] == 0)
        {
            hasFirstColZero = true;
            break;
        }
    }

    for(int iter = 0; iter < row; iter++)
    {
        if(A[0][iter] == 0)
        {
            hasFirstRowZero = true;
            break;
        }
    }
    for(int iter = 1; iter < row; iter++)
    {
        for(int jter = 1; jter < col; jter++)
        {
            if(A[iter][jter] == 0)
            {
                A[0][jter] = 0;
                A[iter][0] = 0;
            }
        }
    }


    for(int iter = 1; iter < row; iter++)
    {
        if(A[iter][0] == 0)
        {
            for(int jter = 1; jter < col; jter++)
            {
                A[iter][jter] = 0;
            }
        }
    }

    for(int iter = 1; iter < col; iter++)
    {
        if(A[0][iter] == 0)
        {
            for(int jter = 1; jter < row; jter++)
            {
                A[jter][iter] = 0;
            }
        }
    }

    if(hasFirstRowZero)
    {
        for(int iter = 0; iter < col; iter++)
        {
            A[0][iter] = 0;
        }
    }

    if(hasFirstColZero)
    {
        for(int jter = 0; jter < row ;jter++)
        {
            A[jter][0] = 0;
        }
    }
    return A;
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
        vector<vector<int> > v;
        for(int iter = 0; iter < n; iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < n; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            v.push_back(temp);
        }
        vector<vector<int> > ans = sol.makeZeros(v);
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
