#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> strange_sort(vector<int> &A, vector<int> &B);
};
Solution::Solution(){}
vector<int> Solution::strange_sort(vector<int> &A, vector<int> &B)
{
    sort(B.begin(), B.end());
    int jter = 0;
    for(int iter = 0; iter < A.size(); iter++)
    {
        if(A[iter] == -9999)
        {
            A[iter] = B[jter++];
        }
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
        int m;
        cin >> m;
        vector<int> v;
        vector<int> a;
        for(int iter = 1; iter <= n; iter++)
        {
            if(iter == m)
            {
                int data;
                cin >> data;
                //cout << data <<" -->" << iter<<  endl;
                v.push_back(data);

            }
            else
            {
                int data;
                cin >> data;
                a.push_back(data);
                v.push_back(-9999);
            }
        }
        vector<int> ans = sol.strange_sort(v, a);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
