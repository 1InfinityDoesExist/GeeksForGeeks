#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string largestNumberFormed(vector<string> &A);
};
Solution::Solution(){}
bool comp(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1 : 0;
}
string Solution::largestNumberFormed(vector<string> &A)
{
    string str = "";
    sort(A.begin(), A.end(), comp);
    for(int iter = 0; iter < A.size(); iter++)
    {
        str = str + A[iter];
    }
    return str;
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
        vector<string> A;
        for(int iter = 0; iter < n; iter++)
        {
            string str;
            cin >> str;
            A.push_back(str);
        }
        string ans = sol.largestNumberFormed(A);
        cout << ans <<endl;
    }
    return 0;
}
