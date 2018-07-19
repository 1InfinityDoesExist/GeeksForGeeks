#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void smallestsecond(vector<int> &V);
};
Solution::Solution(){}
void Solution::smallestsecond(vector<int> &A)
{
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    if(A.size() >= 2)
    {
        cout << A[0] << " " << A[1] <<endl;
    }
    else
    {
        cout << "-1" <<endl;
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
        vector<int> V;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            V.push_back(data);
        }
        sol.smallestsecond(V);
    }
    return 0;
}
