#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void firstKdigit(int n, int k);
};
Solution::Solution(){}
void Solution::firstKdigit(int n, int k)
{
    int rem (1);
    int iter (0);
    while(iter < k)
    {
        cout << (rem*10)/n;
        rem = (rem*10)%n;
        iter++;
    }
    return;
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
        int k;
        cin >> k;
        sol.firstKdigit(n, k);
        cout << endl;
    }
    return 0;
}
