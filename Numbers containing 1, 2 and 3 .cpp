#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
         vector<int> check(vector<int> &A);
};
Solution::Solution(){}
bool isValid(int number)
{
    while(number != 0)
    {
        int rem = number%10;
        if(rem != 1 && rem != 2 && rem != 3)
        {
            return false;
        }
        number /= 10;
    }
    return true;
}
vector<int> Solution::check(vector<int> &A)
{
    vector<int> res;
    sort(A.begin(), A.end());
   for(int iter = 0; iter < A.size(); iter++)
   {
       if(isValid(A[iter]))
       {
           continue;
       }
        A[iter] = -1;
      // A.erase(remove(A.begin(), A.end(), A[iter]), A.end());
   }
   A.erase(remove(A.begin(), A.end(), -1), A.end());
   return A;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        vector<int> A;
        int n;
        cin >> n;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        vector<int> ans = sol.check(A);
       // cout << ans.size() <<endl;
        if(ans.size() == 0)
        {
            cout << -1 <<endl;
        }
        else
        {
            for(vector<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
            {
                cout << *iter << " ";
            }
            cout <<endl;
        }
    }
    return 0;
}
