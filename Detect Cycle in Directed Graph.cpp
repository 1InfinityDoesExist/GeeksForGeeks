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
    bool isCyclic();
    bool isCyclicUtil(int iter, bool *visited, bool *restack);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
  //  adj[v].push_back(u);
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
        restack[iter] = false;
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
int main()
{

    //Geeks for geeks example....
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}

