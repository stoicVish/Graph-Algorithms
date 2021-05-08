#include <iostream>
#include <vector>
using namespace std;

void dfs(int src, vector<int> adj[], bool visited[])
{
    if (visited[src])
        return;

    cout << src << " ";
    visited[src] = true;

    for (int i = 0; i < adj[src].size(); i++)
        dfs(adj[src][i], adj, visited);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<int> adj[n];
    bool visited[n] = {false};

    int edges;
    cin >> edges;

    int u, v;
    for (int _ = 0; _ < edges; _++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, adj, visited);
    return 0;
}
