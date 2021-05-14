#include <iostream>
#include <vector>

using namespace std;

void topologicalSort(int u, vector<int> adj[], bool visited[])
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(!visited[v])
            topologicalSort(v,adj,visited);
    }
    cout<<u<<" ";
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> adj[n];

    int edges;
    cin >> edges;

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            topologicalSort(i, adj, visited);

    return 0;
}
