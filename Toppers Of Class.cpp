#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> topKstudents(vector<pair<int, int> > mp, const int k);
};
Solution::Solution(){}
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> Solution::topKstudents(vector<pair<int, int> > mp, const int k)
{
    vector<int> ans;
    sort(mp.begin(), mp.end(), comp);
    set<int> s;
    for(int iter = 0; iter < mp.size(); iter++)
    {
        pair<int, int> p = mp[iter];
        s.insert(p.first);
        if(s.size() <= k)
        {
            ans.push_back(p.second);
        }
        else
        {
            break;
        }
    }
    s.clear();
    return ans;
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
        vector<pair<int, int> > mp;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            mp.push_back(make_pair(data, iter));
        }
        int k;
        cin >> k;
        vector<int> ans = sol.topKstudents(mp, k);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
