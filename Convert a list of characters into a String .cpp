#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string arraytostring(vector<char> v);
};
Solution::Solution(){}
string Solution::arraytostring(vector<char> v)
{
    string str = "";
    for(vector<char>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        str = str + *iter;
    }
    return str;
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
        vector<char> vc;
        for(int iter = 0; iter < n; iter++)
        {
            char data;
            cin >> data;
            vc.push_back(data);
        }
        string str = sol.arraytostring(vc);
        cout << str << endl;
    }
    return 0;
}
