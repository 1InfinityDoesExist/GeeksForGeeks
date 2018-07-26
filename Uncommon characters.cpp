using namespace std;

class Solution
{
    private:
    public:
        Solution();
        string uncommonCharacter(string &str1, string &str2);
};
Solution::Solution(){}
string Solution::uncommonCharacter(string &str1, string &str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    str1.erase(unique(str1.begin(), str1.end()), str1.end());
    str2.erase(unique(str2.begin(), str2.end()), str2.end());

    map<char, int> mp;
    for(string::size_type iter = 0; iter < str1.length(); iter++)
    {
        mp[str1[iter]]++;
    }
    for(string::size_type iter = 0; iter < str2.length(); iter++)
    {
        mp[str2[iter]]++;
    }
    string str3 = "";
    for(map<char, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        //cout << iter->first << " " <<iter->second << " "<<endl;
        if(iter->second == 1)
        {
            str3 = str3 + iter->first;
        }
    }
    return str3;
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
        string str1;
        cin >> str1;
        string str2;
        cin >> str2;
        string ans = sol.uncommonCharacter(str1, str2);
        cout << ans << endl;
    }
    return 0;
}
