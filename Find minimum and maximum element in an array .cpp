#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        pair<long long int, long long int> minmax(vector<long long int> &V);
};
Solution::Solution(){}
pair<long long int, long long int> Solution::minmax(vector<long long int> &A)
{
    sort(A.begin(), A.end());
    return make_pair(A[0], A[A.size()-1]);
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
        vector<long long int> v;
        for(int iter = 0; iter < n; iter++)
        {
            long long int data;
            cin >> data;
            v.push_back(data);
        }
        pair<long long int , long long int> p = sol.minmax(v);
        cout << p.first << " "<< p.second << endl;
    }
    return 0;
}
