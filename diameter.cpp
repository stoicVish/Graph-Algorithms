#include <iostream>
#include <vector>

using namespace std;

void diameterDFS(int start, int depth, vector<int> adj[], int *maxDep, int *vertex, bool visited[])
{
    visited[start] = true;

    if (depth > *maxDep)
    {
        *vertex = start;
        *maxDep = depth;
    }

    for (int v : adj[start])
    {
        if (!visited[v])
            diameterDFS(v, depth + 1, adj, maxDep, vertex, visited);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int edges;
    cin >> edges;

    vector<int> adj[n];

    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int *maxDep = (int *)malloc(sizeof(int));
    *maxDep = 0;

    int *vertex = (int *)malloc(sizeof(int));
    *vertex = 0;

    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    diameterDFS(0, 0, adj, maxDep, vertex, visited);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    *maxDep = 0;

    diameterDFS(*vertex, 0, adj, maxDep, vertex, visited);

    cout << *maxDep;

    return 0;
}
