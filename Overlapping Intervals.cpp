#include<bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0){}
    Interval(int s, int e): start(s), end(e){}
};
class Solution
{
private:
public:
    Solution();
    vector<Interval> merge(vector<Interval> &vi);
};
Solution::Solution(){}
bool comp(Interval &A, Interval &B)
{
    return A.start < B.start;
}
vector<Interval> Solution::merge(vector<Interval> &vi)
{
    vector<Interval> ans;
    int len = vi.size();
    if(len == 0)
    {
        return ans;
    }
    stack<Interval> s;
    sort(vi.begin(), vi.end(), comp);
    s.push(vi[0]);
    for(int iter = 1; iter < vi.size(); iter++)
    {
        Interval topper = s.top();
        if(topper.end < vi[iter].start)
        {
            s.push(vi[iter]);
        }
        else if(topper.end < vi[iter].end)
        {
            topper.end = vi[iter].end;
            s.pop();
            s.push(topper);
        }
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    Interval i;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        vector<Interval> v;
        for(int iter = 0; iter < n; iter++)
        {
            int s, e;
            cin >> s >> e;
            i.start = s;
            i.end = e;
            v.push_back(i);
        }
        vector<Interval> ans = sol.merge(v);
        for(vector<Interval>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            Interval k = *iter;
            cout << k.start << " "<< k.end <<" ";
        }
        cout << endl;
    }
    return 0;
}
