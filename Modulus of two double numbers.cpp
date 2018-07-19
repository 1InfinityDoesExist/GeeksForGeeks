#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();

};
Solution::Solution(){}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        double x;
        cin >> x;
        double y;
        cin >> y;
        cout << fmod(x, y)<<endl;
    }
    return 0;
}
