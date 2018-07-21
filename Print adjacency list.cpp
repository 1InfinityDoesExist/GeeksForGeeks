#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
        int V;
        list<int> *adj;
    public:
        Solution(int V);
        void addEdges(int x, int y);
        void solve();
};
Solution::Solution(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Solution::addEdges(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Solution::solve()
{
    int src;

    for(int iter = 0; iter < V; iter++)
    {
        src = iter;
        queue<int> q;
        if(adj[iter].size() == 0)
        {
            cout << iter <<endl;
            continue;
        }
        for(list<int>::iterator i = adj[src].begin(); i != adj[src].end(); i++)
        {
            q.push(*i);
        }
        cout << src << "->" << " ";
        while(!q.empty())
        {
            if(q.size() == 1)
            {
                cout << q.front();
                q.pop();
                break;
            }
            cout << q.front()<<"->" << " ";
            q.pop();
        }
        cout << endl;
    }
    for(int iter = 0; iter < V; iter++)
    {
        adj[iter].clear();
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int vertices, edges;
        cin >> vertices >> edges;
        Solution sol(vertices);
        for(int iter = 0; iter < edges; iter++)
        {
            int x, y;
            cin >> x >> y;
            sol.addEdges(x, y);
        }

        sol.solve();

    }
    return 0;
}
