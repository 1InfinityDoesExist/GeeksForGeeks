#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void solve(string str);
};
Solution::Solution(){}
void Solution::solve(string str)
{
    int num (1);
    stack<int> rnum;
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == '(')
        {
           cout << num << ' ';
           rnum.push(num);
           num++;
        }
        else if(str[iter] == ')')
        {
            cout << rnum.top() <<' ';
            rnum.pop();
        }
    }
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
        string str;
        cin >> str;
        sol.solve(str);
        cout << endl;
    }
    return 0;
}
