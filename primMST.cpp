#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

#define mp make_pair

int primMST(int start, vector<pair<int, int>> adj[], int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pQ;
    pair<int, int> temp;
    unordered_set<int> visited;

    pQ.push(mp(0, start));

    int result = 0;

    int u, v, weight;
    while (!pQ.empty() && visited.size() != n)
    {
        temp = pQ.top();

        u = temp.second;

        if (visited.find(u) == visited.end())
            result += temp.first;

        visited.insert(u);

        pQ.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            v = adj[u][i].first;
            weight = adj[u][i].second;
            if (visited.find(v) == visited.end())
                pQ.push(mp(weight, v));
        }
    }
    return result;
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

    cout << primMST(0, adj, n);

    return 0;
}
