#include <bits/stdc++.h>
using namespace std;

int N = 1e5;
vector<pair<int, int>> g[N];
vector<bool> vis(N, false);
vector<int> dist(N, 1e9);
vector<int> parent(N, -1);

void prim(int source) {
    set<pair<int, int>> q;
    dist[source] = 0;
    q.insert({0, source});

    while (!q.empty()) {
        auto node = *q.begin();

        int current = node.second;
        int current_weight = node.first;

        q.erase(q.begin());

        if (vis[current])
            continue;
        vis[current] = true;

        for (auto child : g[current]) {
            int neighbor = child.first;
            int weight = child.second;

            if (!vis[neighbor] && weight < dist[neighbor]) {
                q.erase({dist[neighbor], neighbor});
                dist[neighbor] = weight;
                parent[neighbor] = current;
                q.insert({dist[neighbor], neighbor});
            }
        }
    }

   
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    prim(0, n);
}
