using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int countCarry(string x, string y);
};
Solution::Solution(){}
string intToString(int a)
{
    string str = "";
    while(a != 0)
    {
        int rem = a%10;
        str += (rem + '0');
        a = a/10;
    }
    reverse(str.begin(), str.end());
    return str;
}
int Solution::countCarry(string str1, string str2)
{
    int count (0);
  //  string str1 = intToString(x);
//    string str2 = intToString(y);

    size_t n = max(str1.length(), str2.length());
    if(n > str1.length())
    {
        str1 = string(n-str1.length(), '0') + str1;
    }
    if(n > str2.length())
    {
        str2 = string(n-str2.length(), '0') + str2;
    }
    char carry = 0;
    string final (n+1, '0');
    string::const_reverse_iterator ss1 = str1.rbegin(), se1 = str1.rend();
    string::const_reverse_iterator ss2 = str2.rbegin();
    string::reverse_iterator fter = final.rbegin();

    for(; ss1 != se1; ss1++, ss2++, fter++)
    {
        char temp = (*ss1 - '0') + (*ss2 - '0') + carry;
        if(temp > 9)
        {
            carry = 1;
            count++;
            temp = temp-10;
        }
        else
        {
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
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        string x, y;
        cin >> x >> y;
        int ans = sol.countCarry(x, y);
        cout << ans << endl;
    }
    return 0;
}
