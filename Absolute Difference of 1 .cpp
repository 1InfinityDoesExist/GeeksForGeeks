#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        vector<int> solve(vector<int> &A, const int num);
};
Solution::Solution(){}
bool isValid(int n)
{
    vector<int> vi;
    while(n > 0)
    {
        int rem = n%10;
        vi.push_back(rem);
        n /= 10;
    }
    if(vi.size() == 1)
    {
        vi.clear();
        return true;
    }
    for(int iter = 1; iter < vi.size(); iter++)
    {
        if(abs(vi[iter] - vi[iter-1]) != 1)
        {
            return false;
        }
    }
    return true;
}
vector<int> Solution::solve(vector<int> &A, const int num)
{
    vector<int> ans;
    for(vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        if(*iter < num && isValid(*iter))
        {
            ans.push_back(*iter);
        }
    }
    if(ans.size() == 0)
    {
        ans.push_back(-1);
    }
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
        int n;
        cin >> n;
        int num;
        cin >> num;
        vector<int> v;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        vector<int> ans = sol.solve(v, num);
        for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
    return 0;
}
