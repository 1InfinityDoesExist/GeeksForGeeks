#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int evenDivider(int n);
};
Solution::Solution(){}
int Solution::evenDivider(int n)
{
    int count (0);
    int cp = n;
    vector<int> v;
    while(n > 0)
    {
        v.push_back(n%10);
        n /= 10;
    }
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        if(*iter == 0)
        {
            continue;
        }
        else
        {
            if(cp%*iter == 0)
            {
                count++;
            }
        }
    }
    return count;
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
        int ans = sol.evenDivider(n);
        cout << ans <<endl;
    }
    return 0;
}
