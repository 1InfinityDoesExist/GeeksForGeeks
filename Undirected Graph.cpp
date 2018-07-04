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
        void dfs(int src);
        void bfs(int src);
        bool isCyclic();
        bool isCycleUtil(int iter, bool *visited, int parent);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdges(int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}
bool Graph::isCycleUtil(int iter , bool *visited, int parent)
{
    visited[iter] = true;
    for(list<int>::iterator i = adj[iter].begin(); i != adj[iter].end(); i++)
    {
        if(!visited[*i])
        {
            if(isCycleUtil(*i, visited, iter))
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
bool Graph::isCyclic()
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
            if(isCycleUtil(iter, visited, -1))
            {
                return true;
            }
        }
    }
    return false;
}
void Graph::bfs(int src)
{
   bool *visited = (bool *)malloc(sizeof(bool) * V);
   for(int iter = 0; iter < V; iter++)
   {
       visited[iter] = false;
   }
    list<int> q;
    q.push_back(src);
    visited[src] = true;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop_front();
        cout << temp << " ";
        for(list<int>::iterator iter = adj[temp].begin(); iter != adj[temp].end(); iter++)
        {
            if(!visited[*iter])
            {
                q.push_back(*iter);
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
        int temp = s.top();
        s.pop();
        cout << temp << " ";
        for(list<int>::iterator iter = adj[temp].begin(); iter != adj[temp].end(); iter++)
        {
            if(!visited[*iter])
            {
                visited[*iter] = true;
                s.push(*iter);
            }
        }
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
        int c;
        cin >> c;
        int edges;
        cin >> edges;
        for(int iter = 0; iter < edges; iter++)
        {
            int x, y;
            cin >> x >> y;
            g.addEdges(x, y);
        }

        g.bfs(1);
        cout << endl;
        g.dfs(1);
        cout << endl;
        if(g.isCyclic())
        {
            cout << "Yes there is a cycle" <<endl;
        }
        else
        {
            cout << "No there is no any cycle" <<endl;
        }
    }
    return 0;
}
