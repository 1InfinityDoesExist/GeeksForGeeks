#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void ans(const int a, const int b);
};
Solution::Solution(){}
void Solution::ans(const int a, const int b)
{
    if(a > b)
    {
        cout << a << " "<<"is greater than " << b<<endl;
    }
    else if(a < b)
    {
        cout << a << " is less than " << b <<endl;
    }
    else
    {
        cout << a << " is equals to " << b << endl;
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
        int a, b;
        cin >> a >> b;
        sol.ans(a, b);
    }
    return 0;
}
