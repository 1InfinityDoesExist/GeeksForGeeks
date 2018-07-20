#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        int kthMissingNumber(vector<int> &A, int missingNumber);
};
Solution::Solution(){}
int Solution::kthMissingNumber(vector<int> &A, int missingNumber)
{
   bool mila = false;
   int iter = A[0];
   int jter = 0;
   int count (0);
   for(; iter <= A[A.size()-1]; iter++)
   {
      if(iter == A[jter])
      {
          jter++;
          continue;
      }
      else
      {
          count++;
          if(count == missingNumber)
          {
              mila = true;
              break;
          }
      }
   }
   if(mila)
   {
       return iter;
   }
   return -1;
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
        int n, missingNumber;
        cin >> n >> missingNumber;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        int ans = sol.kthMissingNumber(v, missingNumber);
        cout << ans << endl;
    }
    return 0;
}
