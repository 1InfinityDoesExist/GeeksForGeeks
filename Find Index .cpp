#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        pair<int, int> firstlast(vector<int> &v, const int n);
};
Solution::Solution(){}
pair<int, int> Solution::firstlast(vector<int> &v, const int n)
{
    int iter (0);
    while(iter < v.size()-1)
    {
        if(v[iter] == n)
        {
            break;
        }
        else
        {
            iter++;
        }
    }
    int jter = v.size()-1;
    while(jter >= 0)
    {
        if(v[jter] == n)
        {
            break;
        }
        else
        {
            jter--;
        }
    }
    return make_pair(iter, jter);
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
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int num;
        cin >> num;
        pair<int, int> ans = sol.firstlast(v, num);
        cout << ans.first << " "<<ans.second << endl;
    }
    return 0;
}
