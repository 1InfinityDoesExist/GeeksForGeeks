#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        vector<char> v;
    public:
        Solution();
        void removeVowel(string str);
};
Solution::Solution(){
    v.push_back('a');v.push_back('A');
    v.push_back('e');v.push_back('B');
    v.push_back('i');v.push_back('C');
    v.push_back('o');v.push_back('D');
    v.push_back('u');v.push_back('E');

}
void Solution::removeVowel(string str)
{
    string s = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(find(v.begin(), v.end(), str[iter]) == v.end())
        {
            s = s+str[iter];
        }
    }
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    cin.ignore();
    while(testCase--)
    {
        string str;
        getline(cin, str);
        sol.removeVowel(str);
    }
    return 0;
}
