*You are required to complete this method*/
int maxArea(int M[MAX][MAX],int n,int m)
{
    //Your code here

    int *left = (int *)malloc(sizeof(int) * m);
    for(int iter = 0; iter < m; iter++)
    {
        left[iter] = 0;
    }

    int *right = (int *)malloc(sizeof(int) * m);
    for(int iter = 0; iter < m ;iter++)
    {
        right[iter] = m;
    }
    int *height = (int *)malloc(sizeof(int) *m);
    for(int iter = 0; iter < m; iter++)
    {
        height[iter] = 0;
    }
    int maxAns = 0;
    for(int iter = 0; iter < n; iter++)
    {
        int current_left = 0;
        int current_right = m;
        for(int jter = 0; jter < m; jter++)
        {
            if(M[iter][jter] == 1)
            {
                height[jter]++;
            }
            else
            {
                height[jter] = 0;
            }
        }

        for(int jter = 0; jter < m; jter++)
        {
            if(M[iter][jter] == 1)
            {
                left[jter] = max(left[jter] , current_left);
            }
            else
            {
                left[jter] = 0;
                current_left = jter+1;
            }
        }

        for(int jter = m; jter >= 0; jter--)
        {
            if(M[iter][jter] == 1)
            {
                right[jter] = min(right[jter], current_right);
            }
            else
            {
                right[jter] = m;
                current_right = jter;
            }
        }
        for(int iter = 0; iter < m ;iter++)
        {
            maxAns = max(maxAns, (right[iter] - left[iter]) * height[iter]);
        }
    }
    return maxAns;
}
