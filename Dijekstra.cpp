#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int INF = 1e9;
vector<pair<int,int>> g[N];
vector<bool> vis;
vector<int> dist(N, INF);

void dijekstra(int source) {
    set<pair<int, int>> q;
    dist[source] = 0; 
    q.insert({0, source});
    while (!q.empty()) {
        auto node = *q.begin();
        int v = node.second;
        int v_dist = node.first;
        q.erase(q.begin());
        if (vis[v])
            continue;
        vis[v] = 1;
        for (auto child : g[v]) {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v]) {
                dist[child_v] = dist[v] + wt;
                q.insert({dist[child_v], child_v});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;int test=0;
    while (t--) {
      test++;
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int x, y, wt;
            cin >> x >> y >> wt;
            g[x].push_back({y, wt});
            g[y].push_back({x, wt});
        }

        dist.assign(n + 1, INF);
        vis.assign(n + 1, false);
        dijekstra(1);

        if (dist[n] == INF)
           cout <<"Case "<<test<<": Impossible"<< endl;
        else
            cout <<"Case "<<test<<": "<< dist[n] << endl;

        for (int i = 0; i <= n; i++) {
            g[i].clear();  
        }
    }
}
