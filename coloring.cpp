#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N = 105;
int G[N][N];             // Adjacency Matrix
int max_color;
int nodes;
vector<int> color;
int count_ways = 0;

bool isSafe(int k, int c) {
    for (int i = 0; i < nodes; i++) {
        if (G[k][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

void graphColoring(int k) {
    if (k == nodes) {
        count_ways++;
        return;
    }

    for (int c = 0; c < max_color; c++) {
        if (isSafe(k, c)) {
            color[k] = c;
            graphColoring(k + 1);
            color[k] = -1; // Backtrack
        }
    }
}

void solve() {
    cin >> nodes >> max_color;
    
    int edges;
    cin >> edges;

    // Initialize graph
    memset(G, 0, sizeof(G));
    color.assign(nodes, -1);
    count_ways = 0;

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }

    graphColoring(0);
    cout << "Number of valid colorings = " << count_ways << "\n";
}

int32_t main() {
    make_faster;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
