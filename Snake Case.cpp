#include<bits/stdc++.h>
using namespace std;
const string SPACE = " ";

class Solution
{
    private:
    public:
        Solution();
        void solve(string str);        
};
Solution::Solution(){}
string ltrim(const string& str)
{
    size_t start = str.find_first_not_of(SPACE);
    return (start == string::npos) ? "":str.substr(start);
}
string rtrim(const string& str)
{   
    size_t end = str.find_last_not_of(SPACE);
    return (end == string::npos) ? "": str.substr(0, end+1);
    
}
void Solution::solve(string strr)
{
    string str = rtrim(ltrim(strr));
    queue<string> q;
    string s = "";
    
   
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        
        if(str[iter] == ' ')
        {
            if(s.length() == 0)
            {
                q.push("-1");
                continue;
            }
            else
            {
                q.push(s);
                s = "";
            }
        }
        else
        {
            str[iter] = tolower(str[iter]);
            s = s + str[iter];
            if(iter == str.length()-1)
            {
                q.push(s);
                break;
            }
        }
    }
    while(!q.empty())
    {
        if(q.size() == 1)
        {
            cout << q.front();
            q.pop();
            return;
        }
        
        if(q.front() == "-1")
        {
            cout <<'_';
            q.pop();
        }
        else
        {
            cout << q.front()<<'_';
            q.pop();
        }
    }
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
        int n;
        cin >> n;
        cin.ignore();
        string str;
        getline(cin, str);
        sol.solve(str);
        cout << endl;
    }
    return 0;
}
