#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void solve();
};
Solution::Solution(){}
void Solution::solve()
{
    int n;
    cin >> n;
    int *A = (int *)malloc(sizeof(int) * n);
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        A[iter] = data;
    }
    int *B = (int *)malloc(sizeof(int) * n);
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        B[iter] = data;
    }

    int countA (0);
    int countB (0);
    for(int iter = 0; iter < n ;iter++)
    {
        if(A[iter] > B[iter])
        {
            countA++;
        }
        else if(A[iter] < B[iter])
        {
            countB++;
        }
        else
        {
            continue;
        }
    }

    if(countA > countB)
    {
        cout << countA << " "<<countB <<" "<< 'A' <<endl;
    }
    else if(countA < countB)
    {
        cout << countA << " " << countB << " "<< 'B' <<endl;
    }
    else
    {
        cout << countA << " "<<countB << " "<< "DRAW" <<endl;
    }
    free(A);
    free(B);
    return;
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
        sol.solve();
    }
    return 0;
}
