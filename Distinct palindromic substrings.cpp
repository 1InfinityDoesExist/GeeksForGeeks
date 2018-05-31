#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int distinctPalindromeSubstring(string str);
};
Solution::Solution(){}
int Solution::distinctPalindromeSubstring(string str)
{
    int count (0);
    vector<string> vstr;
    int n = str.length();
    bool table[n][n];
    memset(table, 0, sizeof(table));

    map<char, int> mp;
    map<string, int> mps;
    int maxlength(0);

    //looking for single.....
    for(int iter = 0; iter < n; iter++)
    {
        table[iter][iter] = true;
        mp[str[iter]]++;

    }
    int add = mp.size();
    maxlength = 1;
    //now looking for two.....
    int start = 0;
    for(int iter = 0; iter < n-1; iter++)
    {
        string st = "";
        if(str[iter] == str[iter+1])
        {
            table[iter][iter+1] = true;
            st += str[iter] + str[iter+1];
          // cout << st << endl;
            mps[st]++;
        }
    }
     maxlength = 2;
    int ad = mps.size();

   // cout << ad << endl;
    mps.clear();
    for(int kter = 3; kter <= n; kter++)
    {
        for(int iter = 0; iter < n-kter+1; iter++)
        {
            int jter = iter+kter-1;
            if(table[iter+1][jter-1] && str[iter] == str[jter])
            {
                table[iter][jter] = true;
                start = iter;
                maxlength = kter;
               // cout << str.substr(start, maxlength) << endl;
                mps[str.substr(start, start+maxlength-1)]++;
            }
        }
    }

   return mps.size() + add + ad;
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
        string str;
        cin >> str;
        int ans = sol.distinctPalindromeSubstring(str);
        cout << ans << endl;
    }
    return 0;
}
