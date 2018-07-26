#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int firstIndexOfOne(vector<int> &A);
};
Solution::Solution(){}
int Solution::firstIndexOfOne(vector<int> &A)
{

/*
    int cnt = count(A.begin(), A.end(), 0);
    if(cnt == A.size())
    {
        return -1;
    }
    for(int iter = 0; iter < A.size(); iter++)
    {
        if(A[iter] == 1)
        {
            return iter;
        }
        else
        {
            continue;
        }
    }
*/
    if(A.size() == count(A.begin(), A.end(), 0))
    {
        return -1;
    }
    vector<int>::iterator iter = find(A.begin(), A.end(), 1);
    return iter - A.begin();
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
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.firstIndexOfOne(v);
        cout << ans <<endl;
    }
    return 0;
}
