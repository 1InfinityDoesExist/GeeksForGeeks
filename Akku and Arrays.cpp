#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void solve(vector<int> &A, int queries);
};
Solution::Solution(){}
bool isInc(vector<int> &v)
{
    for(int iter = 1; iter < v.size(); iter++)
    {
        if(v[iter] < v[iter-1])
        {
            return false;
        }
    }
    return true;
}
bool isDesc(vector<int> &v)
{
    for(int iter = v.size()-2; iter >= 0; iter--)
    {
        if(v[iter] < v[iter+1])
        {
            return false;
        }
    }
    return true;
}
void Solution::solve(vector<int> &A, int queries)
{
    for(int iter = 0; iter < queries; iter++)
    {
        int num;
        cin >> num;
        if(num == 1)
        {
            int x, y;
            cin >> x >> y;
            if(x-1 >= 0 && x-1 < A.size())
            {
                A[x-1] = y;
            }
            continue;
        }
        if(num == 2)
        {
            int left, right;
            cin >> left >> right;
            vector<int> v;
            if(left-1 >= 0 && left-1 <= right-1 && right-1 >= left-1 && right-1 < A.size())
            {
                for(int iter = left-1; iter <= right-1; iter++)
                {
                    v.push_back(A[iter]);
                }

                if(isInc(v) && isDesc(v))
                {
                    cout <<-1<< endl;
                    continue;
                }
                else if(isInc(v))
                {
                    cout <<0<< endl;
                    continue;
                }
                else if(isDesc(v))
                {
                    cout <<1<< endl;
                    continue;
                }
                else
                {
                    cout <<-1<< endl;
                    continue;
                }
            }
        }
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
        vector<int> A;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        int queries;
        cin >> queries;
        sol.solve(A, queries);
    }
    return 0;
}
