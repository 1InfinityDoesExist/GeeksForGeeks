#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        pair<int, int> lastRepeated(vector<int> &A);
};
Solution::Solution(){}
pair<int, int> Solution::lastRepeated(vector<int> &A)
{
    pair<int, int> p;
    map<int, int> mp;
    for(int iter = 0; iter < A.size(); iter++)
    {
        mp[A[iter]]++;
    }
    if(mp.size() == A.size())
    {
        return make_pair(-1, -1);
    }
    else
    {
        for(int iter = A.size()-1; iter >= 0; iter--)
        {
            if(iter != 0)
            {
                if(A[iter] == A[iter-1])
                {
                    p = make_pair(A[iter], iter);
                    return p;
                }
            }
        }
    }
    return make_pair(-1, -1);
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
        pair<int, int> p = sol.lastRepeated(v);
        if(p.first == -1 && p.second == -1)
        {
             cout << -1 << endl;
        }
        else
        {
            cout << p.second << " " << p.first << endl;
        }
    }
    return 0;
}
