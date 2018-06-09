#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    bool subarray_with_given_sum(vector<int> &v, const int k);
};
Solution::Solution(){}
bool Solution::subarray_with_given_sum(vector<int> &A, const int k)
{
    int n = A.size();
    int start = 0;
    int iter (1);
    int curr_sum = A[0];
    while(iter < n)
    {
        if(curr_sum > k && start < iter-1)
        {
            curr_sum = curr_sum - A[start++];
           // start++;
        }
        if(curr_sum == k)
        {
            return 1;
        }
        if(iter < n)
        {
            curr_sum = curr_sum + A[iter];
        }
        iter++;
    }
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
        int sum;
        cin >> sum;
        vector<int> v;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            v.push_back(data);
        }
        bool mila = sol.subarray_with_given_sum(v, sum);
        if(mila)
        {
            cout << "Exist" << endl;
        }
        else{
                cout << "Does't Exist << endl";
        }

    }
    return 0;
}
