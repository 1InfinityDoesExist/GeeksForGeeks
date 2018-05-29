#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    public:
        Solution();
};
Solution::Solution(){}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {

        int vertices;
        cin >> vertices;
        int edges;
        cin >> edges;
         vector<int> adj[vertices];
        for(int iter = 0; iter < edges; iter++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        int sum (0);
        for(auto iter = 0; iter < vertices; iter++)
        {
            sum += adj[iter].size();
        }

        cout << sum <<endl;
    }
    return 0;
}
