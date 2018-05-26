

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
/*You are required to complete this method*/
bool comp(val a, val b)
{
    if(a.first == b.first)
    {
        return a.first < b.first;
    }
    return a.first < b.first;
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p, p+n, comp);
    int *temp = (int *)malloc(sizeof(int) * n);
    for(int iter = 0; iter < n; iter++)
    {
        temp[iter] = 1;
    }
    for(int iter = 1; iter < n ;iter++)
    {
        for(int jter = 0; jter < iter; jter++)
        {
            if(p[iter].first > p[jter].second && temp[iter] < temp[jter]+1)
            {
                temp[iter] = temp[jter]+1;
            }
        }
    }
    int max (0);
    for(int iter = 0; iter < n; iter++)
    {
        if(max < temp[iter])
        {
            max = temp[iter];
        }
    }
    free(temp);
    return max;
}
