#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int findTriplate(vector<int> &A, int sum);
};
Solution::Solution(){}
int Solution::findTriplate(vector<int> &A, int sum)
{
    int left, right;
    sort(A.begin(), A.end());
    for(int iter = 0; iter < A.size()-2; iter++)
    {
        left = iter+1;
        right = A.size()-1;
        while(left < right)
        {
            if(A[iter]+A[left] + A[right] == sum)
            {
                return 1;
            }
            else if(A[iter] + A[left] + A[right] < sum)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return 0;
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
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.findTriplate(v, sum);
        cout << ans << endl;
    }
    return 0;
}
