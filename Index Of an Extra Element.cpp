Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below*/
int findExtra(int a[],int b[],int n)
{
 //add code here.
    map<int, int> mp;
    for(int iter = 0; iter <= n; iter++)
    {
        mp[a[iter]]++;
    }
    for(int jter = 0; jter < n; jter++)
    {
        mp[b[jter]]++;
    }

    for(int iter = 0; iter <= n; iter++)
    {
        if(mp[a[iter]] == 1)
        {
            return iter;
        }
    }
}
