#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void kdividerorNot(string str, const int k);
};
Solution::Solution(){}
void Solution::kdividerorNot(string str, const int k)
{
    int len = str.length();
    map<string, int> mp;
    if(len % k == 0)
    {
        map<char, int> check;
        for(string::size_type iter = 0; iter < str.length(); iter++)
        {
            check[str[iter]]++;
        }
        if(check.size() == len)
        {
            cout << "1" << endl;
            return;
        }

        for(string::size_type iter = 0; iter < len; iter = iter+k)
        {
            string s = str.substr(iter, k);
            mp[s]++;
        }
        if(len/k == 2 && mp.size() == 2)
        {
            cout << "1" <<endl;
            return;
        }
       if(mp.size() == 1)
       {
           cout << "1" <<endl;
           return;
       }
       else if(mp.size() > 2)
       {
           cout << "0" << endl;
           return;
       }

    }
    else
    {
        cout << "0" << endl;
        return;
    }
    return;
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
        string str;
        cin >> str;
        int k;
        cin >> k;
        sol.kdividerorNot(str, k);
    }
    return 0;
}
