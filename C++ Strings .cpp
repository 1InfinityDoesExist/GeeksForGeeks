#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void show(string str1, string str2);
};
Solution::Solution(){}
int mx(int x, int y)
{
    return x > y ? x : y;
}
void Solution::show(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int mx = max(len1, len2);
    cout << mx <<endl;
    cout <<str1+str2 <<endl;
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
        string str1, str2;
        cin >> str1 >> str2;
        sol.show(str1, str2);
    }
    return 0;
}
