{
#include <bits/stdc++.h>
using namespace std;
void convertToRoman(int ) ;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;

	convertToRoman(N);
	cout<<endl;

	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*you are required to complete
this function*/
void convertToRoman(int n)
{
//Your code here
    vector<char> vc;
    vc.push_back('I');
    vc.push_back('V');
    vc.push_back('X');
    vc.push_back('L');
    vc.push_back('C');
    vc.push_back('D');
    vc.push_back('M');
    string str = "";
    int i = 0;
    while(n > 0)
    {
        int rem = n%10;
        if(rem <= 3)
        {
            for(int iter = 0; iter < rem; iter++)
            {
                str = vc[i] + str;
            }
        }
        else if(rem == 4)
        {
            str = vc[i+1] + str;
            str = vc[i] + str;
        }
        else if(rem > 4 && rem < 9)
        {
            for(int iter = 5; iter < rem; iter++)
            {
                str = vc[i] + str;
            }
            str = vc[i+1] + str;
        }
        else if(rem == 9)
        {
            str = vc[i+2] + str;
            str = vc[i] + str;
        }
        i = i + 2;
        n /= 10;
    }
    cout << str;
}
