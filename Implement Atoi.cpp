{
 #include <bits/stdc++.h>
using namespace std;
int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
int atoi(string str)
{
    //Your code here
    string ans = "";
    bool neg = false;
    if(str[0] == '-')
    {
        neg = true;
    }
    if(neg == false)
    {
        for(string::size_type iter = 0; iter < str.length(); iter++)
        {
            if(isdigit(str[iter]))
            {
                ans = ans + str[iter];
            }
            else
            {
                return -1;
            }
        }
        return stoi(ans);
    }
    else
    {
        for(string::size_type iter = 1; iter < str.length(); iter++)
        {
            if(isdigit(str[iter]))
            {
                ans = ans + str[iter];
            }
            else
            {
                return -1;
            }
        }
        return stoi(ans) * -1;

    }
}
