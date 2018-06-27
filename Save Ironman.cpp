#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int bachakenahi(string str);

};
Solution::Solution(){}
int Solution::bachakenahi(string str){
    string str_copy = "";
    for(string::size_type iter = 0; iter < str.length(); iter++)
    {
        if(str[iter] >= 'a' && str[iter] <= 'z' || str[iter] >= 'A' && str[iter] <= 'Z')
        {
            if(isupper(str[iter])){
                str[iter] = tolower(str[iter]);
                str_copy += str[iter];
            }
            else if(islower(str[iter])){
                str_copy += str[iter];
            }
        }
        if(isalnum(str[iter]))
        {
            str_copy += str[iter];
        }
    }
   // cout << str_copy << endl;
    int start = 0;
    int end = str_copy.length()-1;

    while(start < end){
        if(str_copy[start++] != str_copy[end--])
        {
            return 0;
        }
    }
    return 1;
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

        int ans = sol.bachakenahi(str);
        if(ans){
            cout << "YES" <<endl;
        }
        else{
            cout << "NO" <<endl;
        }
    }
    return 0;
}
