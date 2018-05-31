#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
        void sortByFrequency(vector<int> &A);
};
Solution::Solution(){}
bool comp(pair<int, int> &A, pair<int, int> &B)
{
    if(A.second == B.second)
    {
        return A.first < B.first;
    }
    return A.second > B.second;
}
void Solution::sortByFrequency(vector<int> &A)
{
    map<int, int> mp;
    for(int iter = 0; iter < A.size(); iter++)
    {
        mp[A[iter]]++;
    }
    vector<pair<int , int> > vp;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int iter = 0; iter < A.size(); iter++)
    {
        vp.push_back(make_pair(A[iter], mp[A[iter]]));
    }
    sort(vp.begin(), vp.end(), comp);
    for(vector<pair<int ,int> >::iterator iter = vp.begin(); iter != vp.end(); iter++)
    {
        pair<int, int> p = *iter;
        int freq = p.second;
        while(freq--)
        {
            cout << p.first << " ";
        }
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
        int n;
        cin >> n;
        vector<int> A;
        for(int iter = 0; iter < n ;iter++)
        {
            int data;
            cin >> data;
            A.push_back(data);
        }
        sol.sortByFrequency(A);
    }
    return 0;
}
