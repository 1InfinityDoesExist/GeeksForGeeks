#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int v);

};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::BFS(int v)
{
    vector<int> res;
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        res.push_back(temp);
        for(list<int>::iterator iter = adj[temp].begin(); iter != adj[temp].end(); iter++)
        {
            if(!visited[*iter])
            {
                q.push(*iter);
                visited[*iter] = true;
            }
        }
    }
    for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        cout << *iter << " ";
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 6);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(6, 7);

    g.BFS(0);
    return 0;
}
