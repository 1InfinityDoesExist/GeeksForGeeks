
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this function*/
void printMat(int M[MAX][MAX],int row,int col)
{
//Your code here
   vector<vector<int> > v;
    for(int iter = 0; iter < row; iter++)
    {
        vector<int> temp;
        for(int jter = 0; jter < col; jter++)
        {
            temp.push_back(M[iter][jter]);
        }
        if(find(v.begin(), v.end(), temp) == v.end())
        {
            for(vector<int>::iterator jter = temp.begin(); jter != temp.end(); jter++)
            {
                cout << *jter << " ";
            }
            cout << '$';
        }
        v.push_back(temp);
    }
}
