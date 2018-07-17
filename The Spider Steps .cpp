#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int spiderSteps(int height, int climb, int steps);
};
Solution::Solution(){}
int Solution::spiderSteps(int height, int climb, int steps)
{
    int totalClimb (0);
    int s (1);

    while(1)
    {
        if((totalClimb+climb) > height)
        {
            return s;
        }

        totalClimb = totalClimb + climb - steps;
        s++;

    }
    return s;
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
        int heightOfWell;
        cin >> heightOfWell;
        int climb;
        cin >> climb;
        int slip;
        cin >> slip;
        int ans = sol.spiderSteps(heightOfWell, climb, slip);
        cout << ans << endl;
    }
    return 0;
}
