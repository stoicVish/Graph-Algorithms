#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

int kruskalMST(vector<pair<int, pair<int, int>>> arr, int n)
{
    int result = 0;

    unordered_set<int> mem;

    int weight, u, v;
    for (int i = 0; i < arr.size() && mem.size() != n; i++)
    {
        weight = arr[i].first;
        u = arr[i].second.first;
        v = arr[i].second.second;
        if (mem.find(u) != mem.end() && mem.find(v) != mem.end())
            continue;
        result += weight;
        mem.insert(u);
        mem.insert(v);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int edges;
    cin >> edges;
    vector<pair<int, pair<int, int>>> adj(edges);

    int u, v, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> weight;
        adj[i] = mp(weight, mp(u, v));
    }

    sort(adj.begin(), adj.end());

    cout << kruskalMST(adj, n);

    return 0;
}
