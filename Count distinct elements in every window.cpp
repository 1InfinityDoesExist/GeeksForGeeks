Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*You are required to complete below method */
int distElement(vector<int> &A)
{
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
   // cout << A.size()<< endl;
    return A.size();
}
void countDistinct(int A[], int k, int n)
{
    //Your code here
    vector<int> res;
    vector<int> vec;
    for(int iter = 0; iter < n ;iter++)
    {
        vec.push_back(A[iter]);
    }
        for(int iter = 0; iter < vec.size()-k+1; iter++)
        {
            int jter = iter+k-1;
            vector<int> checker;
            for(int pter = iter ; pter <= jter; pter++)
            {
                checker.push_back(vec[pter]);
            }
            res.push_back(distElement(checker));
        }

    for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        cout << *iter << " ";
    }
}
