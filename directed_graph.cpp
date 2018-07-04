#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdges(int x, int y);
    void bfs(int src);
    void dfs(int src);
    bool isCyclic();
    bool isCyclicUtil(int x, bool *visited, bool *restack);
    void topologicalSort();
    void topo(int iter, bool *visited, stack<int> &s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdges(int x, int y)
{
    adj[x].push_back(y);
}
void Graph::bfs(int src)
{
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(list<int>::iterator iter = adj[v].begin(); iter != adj[v].end(); iter++)
        {
            if(!visited[*iter])
            {
                q.push(*iter);
                visited[*iter] = true;
            }
        }
    }
    return;
}
void Graph::dfs(int src)
{
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    stack<int> s;
    s.push(src);
    visited[src] = true;
    while(!s.empty())
    {
        int v = s.top();
        s.pop();
        cout << v << " ";
        for(list<int>::iterator iter = adj[v].begin() ;iter != adj[v].end() ;iter++)
        {
            if(!visited[*iter])
            {
                s.push(*iter);
                visited[*iter] = true;
            }
        }
    }
    return;
}
bool Graph::isCyclic()
{
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    bool *restack = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        restack[iter] = true;
    }
    for(int iter = 0; iter < V; iter++)
    {
        if(!visited[iter])
        {
            if(isCyclicUtil(iter, visited, restack))
            {
                return true;
            }
        }
    }
    return false;
}
bool Graph::isCyclicUtil(int iter, bool *visited, bool *restack)
{
    visited[iter] = true;
    restack[iter] = true;
    for(list<int>::iterator i = adj[iter].begin(); i != adj[iter].end(); i++)
    {
        if(!visited[*i])
        {
            if(isCyclicUtil(*i, visited, restack))
            {
                return true;
            }
        }
        else if(restack[*i])
        {
            return true;
        }
    }
    restack[iter] = false;
    return false;
}
void Graph::topo(int iter, bool *visited, stack<int> &s)
{
    visited[iter] = true;
    for(list<int>::iterator i = adj[iter].begin(); i != adj[iter].end(); i++)
    {
        if(!visited[*i])
        {
            topo(*i, visited, s);
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
            topo(iter, visited, s);
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
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int V;
        cin >> V;
        Graph g(V);
        int edges;
        cin >> edges;
        for(int iter = 0; iter < edges; iter++)
        {
            int u, v;
            cin >> u >> v;
            g.addEdges(u, v);
        }
        g.bfs(5);
        cout << endl;
        g.dfs(5);
        cout << endl;
        if(g.isCyclic())
        {
            cout << "It is cyclic" << endl;
        }
        else{
            g.topologicalSort();
        }
    }
    return 0;
}
