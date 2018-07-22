#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> oddeven(vector<int> &A);
};
Solution::Solution(){}
vector<int> Solution::oddeven(vector<int> &A)
{
    vector<int> odd;
    vector<int> even;
    for(vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        if(*iter %2 == 0)
        {
            even.push_back(*iter);
        }
        else
        {
            odd.push_back(*iter);
        }
    }
    A.clear();
    int n = odd.size();
    int m = even.size();
    int iter (0);
    int jter (0);
    while(iter < n && jter < m)
    {
        A.push_back(even[jter]);
        A.push_back(odd[iter]);
        iter++;
        jter++;
    }
    while(iter < n)
    {
        A.push_back(odd[iter]);
        iter++;
    }
    while(jter < m)
    {
        A.push_back(even[jter]);
        jter++;
    }

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
        int n;
        cin >> n;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        vector<int> ans = sol.oddeven(v);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
