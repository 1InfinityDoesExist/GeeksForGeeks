{
#include<bits/stdc++.h>
using namespace std;

string multiplyStrings(string , string );

int main() {

    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;

    	cout<<multiplyStrings(a,b)<<endl;
    }

}
}
///java
//return new java.math.BigInteger(num1).multiply(new java.math.BigInteger(num2)).toString();


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete below function */
string multiplyStrings(string s1, string s2)
{

   int neg = 0;
   if(s1[0] == '-')
   {
        neg++;
        s1.erase(s1.begin());
   }
   if(s2[0] == '-')
   {
       neg++;
       s2.erase(s2.begin());
   }
    int len1 = s1.length();
   int len2 = s2.length();
   string final(len1+len2, '0');
   int iter = len1-1;

   while(iter >= 0)
   {
       int carry = 0;
       int jter = len2-1;
       while(jter >= 0)
       {
           int temp = (s1[iter] - '0') * (s2[jter] - '0') + carry + (final[iter+jter+1] - '0');
           final[iter+jter+1] = temp%10 + '0';
           carry = temp/10;
           jter--;
       }
       final[iter] = final[iter] + carry;
       iter--;
   }
   size_t startpos = final.find_first_not_of('0');
   if(string::npos != startpos)
   {
       string ans = final.substr(startpos);
       if(neg%2 == 0)
       {
           return ans.erase(0, ans.find_first_not_of('0'));
       }
       else
       {
           ans = '-' + ans.erase(0, ans.find_first_not_of('0'));
           return ans;
       }
   }
   return "0";
}
