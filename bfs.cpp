#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int src, vector<int> adj[], bool visited[])
{
    queue<int> q;
    if (visited[src])
        return;
    q.push(src);

    int u;
    while (!q.empty())
    {
        u = q.front();
        cout << u << " ";
        visited[u] = true;
        q.pop();

        for (int i : adj[u])
        {
            if (!visited[i])
                q.push(i);
        }
    }
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

    bfs(0, adj, visited);
    return 0;
}
