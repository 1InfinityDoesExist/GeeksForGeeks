#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	int n, q, i;
	cin>>n>>q;

	int intArr[n];
	string strArr[n];
    float floatArr[n];

	switch(q)
	{
	    case 1:
	    for(i=0; i<n; i++)
	    {
	        cin>>intArr[i];
	    }
	    sortArray(intArr, n);
    	printArray(intArr, n);
    	break;

        case 2:
	    for(i=0; i<n; i++)
	    {
	        cin>>strArr[i];
	    }
	    sortArray(strArr, n);
    	printArray(strArr, n);
    	break;

        case 3:
	    for(i=0; i<n; i++)
	    {
	        cin>>floatArr[i];
	    }
	    sortArray(floatArr, n);
    	printArray(floatArr, n);
    	break;
	}
    }
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
template <class T>
void sortArray(T a[], int n)
{
	//Add your code here.
	bool swapped = true;
	for(int pass = n-2; pass >= 0 && swapped; pass--)
	{
	    swapped = false;
	    for(int iter = 0; iter <= pass; iter++)
	    {
	        if(a[iter] > a[iter+1])
	        {
	            T temp = a[iter];
	            a[iter] = a[iter+1];
	            a[iter+1] = temp;
	            swapped = true;
	        }
	    }
	}
}
template <class T>
void printArray(T a[], int n)
{
	//Add your code here.
	for(int iter = 0; iter < n; iter++)
	{
	    cout << a[iter] <<" ";
	}
	cout << endl;
}
