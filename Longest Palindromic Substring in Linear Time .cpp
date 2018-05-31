/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// your task is to complete this function
void findLongestPalindromicString(char text[])
{

    int n  = strlen(text);
  //  cout << n << endl;
    string str = "";
    for(int iter = 0; iter < n; iter++)
    {
        str = str + text[iter];
    }
  //  cout << str << endl;
    int maxlength = 1;
    int len = str.length();
 //   cout << len <<endl;
    int start = 0;
    int low, high;
    for(int iter = 1; iter < len; iter++)
    {
        low = iter-1;
        high = iter;
        while(low >= 0 && high < len && str[low] == str[high])
        {
            if(high - low + 1 > maxlength)
            {
                maxlength = high-low+1;
                start = low;
            }
            --low;
            ++high;
        }

        low = iter-1;
        high = iter+1;

        while(low >= 0 && high < len && str[low] == str[high])
        {
            if(high-low+1 > maxlength)
            {
                maxlength = high-low+1;
                start = low;
            }
            --low;
            ++high;
        }
    }
   // cout << start << " " <<maxlength <<endl;
   if(maxlength == 1)
   {
       cout << str[1] <<endl;
       return;
   }
    cout << str.substr(start, maxlength) << endl;
    return;


}
