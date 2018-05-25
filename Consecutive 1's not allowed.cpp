#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
       unsigned long long int niki(int x);
};
Solution::Solution(){}
unsigned long long int Solution::niki(int x)
{
    int *temp1 = (int *)malloc(sizeof(int) * x);
    int *temp2 = (int *)malloc(sizeof(int) * x);

    temp1[0] = temp2[0] = 1;
    for(unsigned long long int iter = 1; iter < x; iter++)
    {
        temp1[iter] = (temp1[iter-1]%1000000007 + temp2[iter-1]%1000000007)%1000000007;
        temp2[iter] = temp1[iter-1]%1000000007;
    }
    unsigned long long int ans = (temp1[x-1] + temp2[x-1])%1000000007;
    free(temp1);
    free(temp2);
    return ans;
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
        int n;
        cin >> n;
        unsigned long long int ans = sol.niki(n);
        cout << ans << endl;
    }
    return 0;
}
