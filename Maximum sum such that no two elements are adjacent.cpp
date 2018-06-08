#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int max_sum_no_adj(vector<int> &A);
};
Solution::Solution(){}
int Solution::max_sum_no_adj(vector<int> &A)
{
    if(A.size() == 0)
    {
        return 0;
    }
    int incl = A[0];
    int excl = 0;
    int new_excl;

    for(int iter = 1; iter < A.size(); iter++)
    {
        new_excl = (incl > excl) ? incl : excl;
        incl = excl + A[iter];
        excl = new_excl;
    }
    return (incl > excl) ? incl : excl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    vector<int> v;
    for(int iter = 0; iter < n; iter++)
    {
        int data;
        cin >> data;
        v.push_back(data);
    }
    int ans = sol.max_sum_no_adj(v);
    cout << ans << endl;
    return 0;
}
