#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int CountPerfectSquare(int start, int end);
};
Solution::Solution(){}
int Solution::CountPerfectSquare(int start, int end)
{
    return (floor(sqrt(end)) - ceil(sqrt(start)) +1);
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
        int start, end;
        cin >> start >> end;
        int ans = sol.CountPerfectSquare(start, end);
        cout << ans <<endl;
    }
    return 0;
}
