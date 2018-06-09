#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    bool milakenahi(vector<vector<int> > &v, const int k);
};
Solution::Solution(){}
bool Solution::milakenahi(vector<vector<int> > &v, const int k)
{
    int col = v[0].size();
    int row = v.size();
    int iter = 0;
    int jter = col-1;
    while(iter < row && jter >= 0)
    {
        if(v[iter][jter] == k)
        {
            return 1;
        }
        if(v[iter][jter] > k)
        {
            jter--;
        }
        else{
            iter++;
        }
    }
    return 0;
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
       int row, col;
        cin >> row >> col;
        vector<vector<int> > v;
        for(int iter = 0; iter < row ;iter++)
        {
            vector<int> temp;
            for(int jter = 0; jter < col; jter++)
            {
                int data;
                cin >> data;
                temp.push_back(data);
            }
            v.push_back(temp);
        }
        int k;
        cin >> k;
        int ans = sol.milakenahi(v, k);
        if(ans == 1)
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Nahi mila "<<endl;
        }
    }
    return 0;
}
