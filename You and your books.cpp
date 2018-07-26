{
#include <iostream>
#include<algorithm>
#include<cstdio>
//#include<Windows.h>
using namespace std;
int max_Books(int[], int, int);
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  	int n,k;
  	cin>>n>>k;
  	int ar[n];
  	for(int i=0;i<n;i++)
  	{
  		cin>>ar[i];
  	}
        	cout<<max_Books(ar,n,k)<<endl;

  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are requried to complete this method */
int max_Books(int a[], int n, int k)
{
    // Your code here
    int iter = 0;
    int temp (0);
    int ans (0);
    while(iter < n)
    {
        if(a[iter] <= k)
        {
            temp = temp+a[iter];
        }
        else
        {
            temp = 0;
        }
        ans = max(ans, temp);
        iter++;
    }
    return ans;
}
