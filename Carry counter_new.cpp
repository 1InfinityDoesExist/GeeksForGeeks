// carry Counter...
#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int carryCount(string str1, string str2);
};
Solution::Solution(){}
int max(int x, int y)
{
    return x > y ? x : y;
}
int Solution::carryCount(string str1, string str2)
{
    size_t n = max(str1.length(), str2.length());
    if(n > str1.length())
    {
        str1 = string(n-str1.length(), '0') + str1;
    }
    else if(n > str2.length())
    {
        str2 = string(n - str2.length(), '0') + str2;
    }
    int count (0);
    int carry = 0;
    string final(n+1, '0');
    string::const_reverse_iterator iter = str1.rbegin(), st = str1.rend();
    string::const_reverse_iterator jter = str2.rbegin();
    string::reverse_iterator fter = final.rbegin();
    for(;iter != st; iter++, jter++, fter++)
    {
        char temp = (*iter - '0' + *jter - '0' + carry);
            if(temp > 9)
            {
                carry = 1;
                count++;
                temp = temp - 10;
            }
            else{
                carry = 0;
            }
            *fter = temp + '0';

    }
    final[0] = carry + '0';
    return count;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    string str1;
    cin >> str1;
    string str2;
    cin >> str2;
    int ans = sol.carryCount(str1, str2);
    cout << ans << endl;
    return 0;
}
