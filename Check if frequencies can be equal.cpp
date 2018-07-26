using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int removeAtMostOne(string str);
};
Solution::Solution(){}
bool comp(pair<char, int> &A, pair<char, int> &B)
{
    return A.second < B.second;
}
int Solution::removeAtMostOne(string str)
{
    int mx (0);
    map<char ,int> mp;
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        mp[str[iter]]++;
    }
    int len = mp.size();
    if(len == str.length())
    {
        return true;
    }
    vector<pair<char, int> > vp;
    for(map<char, int>::iterator iter = mp.begin(); iter != mp.end(); iter++)
    {
        vp.push_back(make_pair(iter->first, iter->second));
    }
    sort(vp.begin(), vp.end(),comp);
    for(int iter = 0; iter < vp.size()-1; iter++)
    {
        pair<char, int> last = vp[vp.size()-1];
        int lt = last.second;
        if(abs(vp[iter].second - lt) > 1)
        {
            return false;
        }
        else if(abs(vp[iter].second - lt) == 1)
        {
            mx++;
        }
    }
    if(mx == vp.size()-1 || mx == 1)
    {
        return true;
    }
    else if(mx < vp.size()-1)
    {
        return false;
    }
   // return false;
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
        int ans = sol.removeAtMostOne(str);
        cout << ans <<endl;
    }
    return 0;
}
