#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void changetheString(string str);
};
Solution::Solution(){}
void Solution::changetheString(string str)
{
    if(islower(str[0]))
    {
        for(string::size_type iter = 1; iter < str.length(); iter++)
        {
            str[iter] = tolower(str[iter]);
        }
    }
    else
    {
        for(string::size_type iter = 1; iter < str.length(); iter++)
        {
            str[iter] = toupper(str[iter]);
        }
    }
    cout << str << endl;
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
        sol.changetheString(str);
    }
    return 0;
}
