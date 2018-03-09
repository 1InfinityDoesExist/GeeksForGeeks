#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<pair<int, int> > closestNumber(vector<int> &A);
};
Solution::Solution(){}
vector<pair<int, int> > Solution::closestNumber(vector<int> &A)
{
    map<int, vector<pair<int, int> > > mp;
    sort(A.begin(), A.end());
    int diff = INT_MAX;
    for(int iter = 0; iter < A.size()-1; iter++)
    {
        if(abs(A[iter] - A[iter+1]) < diff)
        {
            diff = abs(A[iter] - A[iter+1]);
            mp[diff].push_back(make_pair(A[iter], A[iter+1]));
        }
    }
    return mp[diff];
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
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<pair<int, int> > ans = sol.closestNumber(A);
        for(vector<pair<int, int> >::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            pair<int, int> p = *iter;
            cout << abs(p.first-p.second) << endl;
        }
    }
    return 0;
}
