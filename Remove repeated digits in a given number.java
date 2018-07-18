#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void removeRepeatedDigit(long long int n);
};
Solution::Solution(){}
void Solution::removeRepeatedDigit(long long int n)
{
    vector<int> v;
    while(n > 0)
    {
        v.push_back(n%10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int iter = 0; iter < v.size(); iter++)
    {
        cout << v[iter];
    }
    cout << endl;
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
        long long int n;
        cin >> n;
        sol.removeRepeatedDigit(n);
    }
    return 0;
}
