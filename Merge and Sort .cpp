#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> merg_sort(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution::merg_sort(vector<int> &A)
{
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
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
        vector<int> v;
        int n;
        cin >> n;
        while(n--)
        {
            int num;
            cin >> num;
            for(int iter = 0; iter < num; iter++)
            {
                int data;
                cin >> data;
                v.push_back(data);
            }
        }
        vector<int> ans = sol.merg_sort(v);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
