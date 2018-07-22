#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int patternMila(string str);
};
Solution::Solution(){}
int Solution::patternMila(string str)
{
   int count (0);
   bool one = false;
   bool zero = false;
   bool alpha = false;
   for(string::size_type iter = 0; iter < str.length(); iter++)
   {
       if(isdigit(str[iter]) && str[iter] == '1')
       {
           if(one == true && alpha == false && zero == true)
           {
               count++;
               one = true;
               alpha = false;
               zero = false;
           }
           else
           {
               one = true;
               alpha = false;
               zero = false;
           }
       }

       else if(isdigit(str[iter]) && str[iter] == '0')
       {
           zero = true;
       }
       else
       {
           alpha = true;
       }
   }
   return count;
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
        int an = sol.patternMila(str);
        cout << an << endl;
    }
    return 0;
}
