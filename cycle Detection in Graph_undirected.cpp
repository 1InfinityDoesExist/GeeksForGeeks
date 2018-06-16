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
    bool isCycle();
    bool isCyclicUtil(int iter, bool *visited, int parent);
    void topologicalSort();
    void DFS(int iter, bool *visited, stack<int> &s);
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

//for topological sort...
void Graph::DFS(int iter , bool *visited, stack<int> &s)
{
    visited[iter] = true;
    for(list<int>::iterator i = adj[iter].begin(); i != adj[iter].end(); i++)
    {
        if(!visited[*i])
        {
            DFS(*i, visited,s);
        }
    }
    s.push(iter);
    return;
}
void Graph::topologicalSort()
{
    bool *visited = (bool *)malloc(sizeof(bool) *V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    stack<int> s;

    for(int iter = 0; iter < V; iter++)
    {
        if(!visited[iter])
        {
            DFS(iter, visited, s);
        }
    }

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return;
}

//for cycle detection....
bool Graph::isCycle()
{
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    for(int iter = 0; iter < V; iter++)
    {
        if(!visited[iter])
        {
            if(isCyclicUtil(iter, visited, -1))
            {
                return true;
            }
        }
    }
    return false;
}
bool Graph::isCyclicUtil(int iter, bool *visited, int parent)
{
    visited[iter] = true;
    for(list<int>::iterator i = adj[iter].begin(); i != adj[iter].end(); i++)
    {
        if(!visited[*i])
        {
            if(isCyclicUtil(*i, visited, iter))
            {
                return true;
            }
        }
        else if(*i != parent)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCycle()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";


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
