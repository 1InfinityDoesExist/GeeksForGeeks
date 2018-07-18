#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int perfectArrayOrNot(vector<int> &A);
};
Solution::Solution(){}
int Solution::perfectArrayOrNot(vector<int> &A)
{
    vector<int> cp = A;
    reverse(cp.begin(), cp.end());
    if(cp == A)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
        vector<int> A;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.perfectArrayOrNot(A);
        if(ans)
        {
            cout << "PERFECT" <<endl;
        }
        else
        {
            cout << "NOT PERFECT" << endl;
        }
    }
    return 0;
}
