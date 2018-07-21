#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        long long int claiming_ticket(vector<long long int> &A);
};
Solution::Solution(){}
int summationofID(long long int num)
{
     int returner (0);
    while(num > 0)
    {
        returner = returner + num%10;
        num /= 10;
    }
    return returner;
}
long long int Solution::claiming_ticket(vector<long long int> &A)
{
    map<int , int> mp;
    for(vector<long long int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        int sum_id = summationofID(*iter);
        mp[sum_id]++;
    }
    return mp.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    long long int testCase;
    cin >> testCase;
    while(testCase--)
    {
        long long int n;
        cin >> n;
        vector<long long int> ticket;
        for(int iter = 0; iter < n; iter++)
        {
            long long int data;
            cin >> data;
            ticket.push_back(data);
        }
        long long int ans = sol.claiming_ticket(ticket);
        cout << ans <<endl;
    }
    return 0;
}
