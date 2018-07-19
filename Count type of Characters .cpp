#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void printChar(string str);
};
Solution::Solution(){}
void Solution::printChar(string str)
{
    int lower (0);
    int upper (0);
    int num (0);
    int special (0);
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] >= 'a' && str[iter] <= 'z')
        {
            lower++;
        }
        else if( str[iter] >= 'A' && str[iter] <= 'Z')
        {
            upper++;
        }
        else if(isdigit(str[iter]))
        {
            num++;
        }
        else
        {
            special++;
        }
    }
    cout << upper << endl;
    cout << lower << endl;
    cout << num << endl;
    cout << special << endl;
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
        string str;
        cin >> str;
        sol.printChar(str);
    }
    return 0;
}
