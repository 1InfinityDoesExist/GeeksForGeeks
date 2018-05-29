int getId(int M[MAX][MAX], int n)
{
    //Your code here
    int count (0);
    for(int iter = 0; iter < n; iter++)
    {
        for(int jter = 0; jter < n; jter++)
        {
            if(M[iter][jter] == 0)
            {
                count++;
            }
        }
    }
    if(count == (n*n))
    {
        return -1;
    }
    if(n == 1)
    {
        return -1;
    }
    int a = 0;
    int b = n-1;
    while(a < b)
    {
        if(M[a][b])
        {
            a++;
        }
        else
        {
            b--;
        }
    }
  //  cout << a <<endl;
    for(int iter = 0; iter < n; iter++)
    {
        if((iter != a) && (M[a][iter] ==1) &&  (M[iter][a] == 0))
        {
            return -1;
        }
    }

    return a;
}
