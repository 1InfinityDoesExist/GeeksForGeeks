#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int maxAreaRectangle(vector<int> &heights);
};
Solution::Solution(){}
int Solution::maxAreaRectangle(vector<int> &heights)
{
    stack<int> s;
    int newArea;
    int maxArea = INT_MIN;
    int iter (0);
    while(iter < heights.size())
    {
        if(s.empty() || heights[s.top()] <= heights[iter])
        {
            s.push(iter++);
        }
        else
        {
            int tp = s.top();
            s.pop();
            newArea = heights[tp] * (s.empty() ? iter : iter-s.top()-1);
            if(maxArea < newArea)
            {
                maxArea = newArea;
            }
        }
    }
    while(!s.empty())
    {
        int tp = s.top();
        s.pop();
        newArea = heights[tp] * (s.empty() ? iter : iter-s.top()-1);
        if(maxArea < newArea)
        {
            maxArea = newArea;
        }
    }
    return maxArea;
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
        vector<int> heights;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            heights.push_back(data);
        }
        int ans = sol.maxAreaRectangle(heights);
        cout << ans << endl;
    }
    return 0;
}
