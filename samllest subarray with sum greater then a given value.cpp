#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int minlength(vector<int> &A, const int sum);
};
Solution::Solution(){}
int Solution::minlength(vector<int> &A, const int sum)
{
    int n = A.size();
    int curr_sum = 0;
    int min_length = INT_MAX;
    int start = 0;
    int end = 0;
    while(end < n)
    {
        while(curr_sum <= sum && end < n)
        {
            curr_sum = curr_sum + A[end++];
        }
        while(curr_sum > sum && start < end)
        {
            if(end - start < min_length)
            {
                min_length = end-start;
            }
            curr_sum -= A[start++];
        }
    }
    return min_length;
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
        int sum;
        cin >> sum;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.minlength(v, sum);
        cout << ans << endl;
    }
    return 0;
}
