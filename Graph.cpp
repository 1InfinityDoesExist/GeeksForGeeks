#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS(int x);
    void BFS(int y);

};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Graph::DFS(int x)
{
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    stack<int> st;
    st.push(x);
    visited[x] = true;
    while(!st.empty())
    {
        int v = st.top();
        st.pop();
        cout << v << " ";
        for(list<int>::iterator iter = adj[v].begin(); iter != adj[v].end(); iter++)
        {
            if(!visited[*iter])
            {
                st.push(*iter);
                visited[*iter] = true;
            }
        }
    }
    cout << endl;
}
void Graph::BFS(int x)
{
    bool *visited = (bool *)malloc(sizeof(bool) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << "  ";
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(0);
    g.BFS(0);

    return 0;
}
