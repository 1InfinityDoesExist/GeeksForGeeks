#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int appearOnlyOnce(vector<int> &A);
};
Solution::Solution(){}
int Solution::appearOnlyOnce(vector<int> &A)
{
    map<int ,int> mp;
    for(int iter = 0; iter < A.size(); iter++)
    {
        mp[A[iter]]++;
    }
    for(map<int, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(iter->second == 1)
        {
            return iter->first;
        }
    }
    return -1;
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
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int ans = sol.appearOnlyOnce(A);
        cout << ans <<endl;
    }
    return 0;
}
