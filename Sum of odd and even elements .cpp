#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        pair<long long int, long long int> sumofOddEven(long long int n);
};
Solution::Solution(){}
pair<long long int, long long int> Solution::sumofOddEven(long long int n)
{
    long long int odd (0);
    long long int even (0);
    pair<long long int , long long int> p;
    for(int iter = 1; iter <= n; iter++)
    {
        if(iter%2 == 0)
        {
            even += iter;
        }
        else
        {
            odd += iter;
        }
    }
    return make_pair(odd, even);
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
        pair<long long int, long long int> p = sol.sumofOddEven(n);
        cout << p.first << " "<<p.second<<endl;
    }
    return 0;
}
