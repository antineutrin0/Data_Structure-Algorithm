#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl cout << endl;

int32_t main() {
    make_faster;
    int n, w;
    cin >> n;

    int timer = 0, reward = 0;

    vector<pair<int, int>> tasks(n); 

    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        tasks[i] = {a, d};
    }

    sort(tasks.begin(), tasks.end(), [](pair<int, int> x, pair<int, int> y) {
        return x.first == y.first ? x.second < y.second : x.first < y.first;
    });

    for (int i = 0; i < n; i++) {
        timer += tasks[i].first;                
        reward += (tasks[i].second - timer);  
    }

    cout << reward << endl;
    return 0;
}
