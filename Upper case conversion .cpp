#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void firstLetterCapital(string str);
};
Solution::Solution(){}
void Solution::firstLetterCapital(string str)
{
    string s = "";
    queue<string> q;
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] == ' ')
        {
            if(s.length() == 0)
            {
                continue;
            }
            else
            {
                s[0] = toupper(s[0]);
                q.push(s);
                s = "";
            }
        }
        else
        {
            s = s + str[iter];
            if(iter == str.length()-1)
            {
                s[0] = toupper(s[0]);
                q.push(s);
            }
        }
    }
    while(!q.empty())
    {
        if(q.size() == 1)
        {
            cout << q.front() <<" ";
            return;
        }

        cout << q.front()<<" ";
        q.pop();
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
    cin.ignore();
    while(testCase--)
    {
        string str;
        getline(cin, str);
        sol.firstLetterCapital(str);
        cout << endl;
    }
    return 0;
}
