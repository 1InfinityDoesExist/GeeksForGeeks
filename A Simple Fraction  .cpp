#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string fraction(int num, int deno);
};
Solution::Solution(){}
string Solution::fraction(int num, int deno)
{
   /* string str = "";
    int64_t n = num, d = deno;
    if(n == 0)
    {
        return "0";
    }
    if(n < 0 ^d < 0)
    {
        str += '-';
    }
    n = abs(n);
    d = abs(d);
    str += to_string(n/d);
    if(n%d == 0)
    {
        return str;
    }
    str += '.';
    unordered_map<int,int > umap;
    for(int64_t r = n%d; r; r %= d)
    {
        if(umap.find(r) != umap.end())
        {
            str.insert(umap[r], 1, '(');
            str += ')';
            break;
        }
        umap[r] = str.size();
        r *= 10;
        str.push_back((char)('0' + (r/d)));
    }
    return str;*/

    string str = "";
    int64_t n = num, d = deno;
    if(n == 0)
    {
        return "0";
    }
    if(n < 0 ^ d < 0)
    {
        str += '-';
    }
    n = abs(n);
    d = abs(d);
    str += to_string(n/d);
    if(n%d == 0)
    {
        return str;
    }
    str += '.';

    unordered_map<int, int> umap;
    for(int64_t r = n%d; r; r %= d)
    {
        if(umap.find(r) != umap.end())
        {
            str.insert(umap[r], 1, '(');
            str += ')';
            break;
        }
        umap[r] = str.size();
        r *= 10;
        str.push_back((char)('0' + (r/d)));
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
        int num, deno;
        cin >> num >> deno;
        string ans = sol.fraction(num, deno);
        cout << ans << endl;
    }
    return 0;
}
