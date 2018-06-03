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
    void topologicalSort();
    void topological(int iter, bool *visited, stack<int> &s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
   // adj[v].push_back(u);
}
void Graph::topological(int iter, bool *visited, stack<int> &s)
{
    visited[iter] = true;
    for(list<int>::iterator i = adj[iter].begin(); i != adj[iter].end(); i++)
    {
        if(!visited[*i])
        {
            topological(*i, visited, s);
        }
    }
    s.push(iter);
    return;
}
void Graph::topologicalSort()
{
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    stack<int> s;
    for(int iter = 0; iter < V; iter++)
    {
        if(!visited[iter])
        {
            topological(iter, visited, s);
        }
    }
    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topologicalSort();
    return 0;
}
