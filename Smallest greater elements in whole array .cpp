#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void nextMaxNumber(vector<int> &A);
};
Solution::Solution(){}
void Solution::nextMaxNumber(vector<int> &A)
{
    map<int, int> mp;
    vector<int> cp = A;
    sort(cp.begin(), cp.end());
    for(int iter = 0; iter < cp.size()-1; iter++)
    {
        mp[cp[iter]] = cp[iter+1];
    }
    for(int iter = 0; iter < A.size(); iter++)
    {
        if(A[iter] == cp[cp.size()-1])
        {
            cout << '_' << " ";
        }
        else
        {
            cout << mp[A[iter]] << " ";
        }
    }
    cout << endl;
    mp.clear();
    A.clear();
    cp.clear();
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
        int n;
        cin >> n;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        sol.nextMaxNumber(v);
    }
    return 0;
}
