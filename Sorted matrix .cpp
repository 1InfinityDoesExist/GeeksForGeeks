#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> printInsorted(vector<vector<int> > &A);
};
Solution::Solution(){}
vector<int> Solution::printInsorted(vector<vector<int> > &A)
{
    vector<int> ans;
    for(int iter = 0; iter < A.size(); iter++)
    {
        for(int jter = 0; jter < A[iter].size(); jter++)
        {
            ans.push_back(A[iter][jter]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
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
        int num;
        cin >> num;
        vector<vector<int> > n;
        for(int iter = 0; iter < num ;iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < num ;jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            n.push_back(temp);
        }
        vector<int> ans = sol.printInsorted(n);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
