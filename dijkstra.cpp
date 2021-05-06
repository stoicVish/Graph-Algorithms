#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define mp make_pair

void dijkstra(int src, vector<pair<int, int>> adj[], int distances[], int parent[], int n)
{
    set<pair<int, int>> pQ;
    set<pair<int, int>>::iterator itr;

    for (int i = 0; i < n; i++)
        distances[i] = INT32_MAX;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    distances[src] = 0;
    pQ.insert(mp(0, src));

    int u, v, weight;
    while (!pQ.empty())
    {
        itr = pQ.begin();
        u = itr->second;
        pQ.erase(itr);

        for (int i = 0; i < adj[u].size(); i++)
        {
            v = adj[u][i].first;
            weight = adj[u][i].second;

            if (distances[v] > distances[u] + weight)
            {
                parent[v] = u;
                if (distances[v] != INT32_MAX)
                    pQ.erase(pQ.find(mp(distances[v], v)));

                distances[v] = distances[u] + weight;
                pQ.insert(mp(distances[v], v));
            }
        }
    }
}

void path(int parent[], int i)
{
    cout << i << " ";
    while (i != parent[i])
    {
        cout << parent[i] << " ";
        i = parent[i];
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    vector<pair<int, int>> adj[n];

    int edges;
    cin >> edges;

    int u, v, weight;
    for (int _ = 0; _ < edges; _++)
    {
        cin >> u >> v >> weight;
        adj[u].push_back(mp(v, weight));
        adj[v].push_back(mp(u, weight));
    }

    int distances[n];
    int parent[n];

    dijkstra(0, adj, distances, parent, n);

    for (int i : distances)
        cout << i << " ";

    for (int i = 0; i < n; i++)
        path(parent, i);

    return 0;
}
