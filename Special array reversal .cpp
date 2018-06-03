#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string reverseArray(string str);
};
Solution::Solution(){}
bool isAlphabet(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
string Solution::reverseArray(string str)
{
   int start = 0;
   int end = str.length()-1;
   while(start < end)
   {
       if(!isAlphabet(str[start]))
       {
           start++;
       }
       else if(!isAlphabet(str[end]))
       {
           end--;
       }
       else
       {
           swap(str[start], str[end]);
            start++;
            end--;
       }
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
        string str;
        cin >> str;
        string ans = sol.reverseArray(str);
        cout << ans <<endl;
    }
    return 0;
}
