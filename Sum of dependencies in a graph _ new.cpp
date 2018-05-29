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
    int countNotReach(int x);
    void BFS(int src, bool *visited);
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
void Graph::BFS(int src, bool *visited)
{
    visited[src] = true;
    list<int>::iterator iter;
    for(iter = adj[src].begin(); iter != adj[src].end(); iter++)
    {
        if(!visited[*iter])
        {
            BFS(*iter, visited);
        }
    }
    return;
}
int Graph::countNotReach(int src)
{
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    BFS(src, visited);
    int count (0);
    for(int iter = 0; iter < V; iter++)
    {
        if(visited[iter] == false)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(6, 7);

    cout << g.countNotReach(2);

    return 0;
}
