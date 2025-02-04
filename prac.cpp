#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl cout << endl;

pair<int, int> pr;
const int N = 1e6 + 5;
vector<int> dp(N, INT_MAX);


void dfs(int n, int parent, vector<int> v[], vector<int>& weight, vector<pair<int, int>>& res) {
    for (auto u : v[n]) {
        if (u != parent) { 
            res.push_back({u, weight[u]});
            dfs(u, n, v, weight, res);
        }
    }
}

pair<int, int> dfs1(int n, int parent, vector<int> v[], vector<int>& weight) {
    for (auto u : v[n]) {
        if (u != parent) {
            if (pr.first < weight[u])
                pr = {weight[u], u};
            dfs1(u, n, v, weight);
        }
    }
    return pr;
}

int32_t main() {
    make_faster;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v[n + 1];
        vector<int> weight(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> weight[i];

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a); 
        }

        if (v[1].size() == 1) { 
            vector<pair<int, int>> res;
            res.push_back({1,weight[1]});
            dfs(1, -1, v, weight, res);
            int flg=0;
            for (int i = 1; i < res.size(); i++) {
                if (res[i].second < res[i - 1].second) {
                    flg=1;
                    cout << res[i].first << endl;
                    break;
                }
            }
            if(flg==0)
                cout<<0<<endl;
        } else { 
            map<int, int> mp;

            for (auto u : v[1]) {
                pr = {weight[u], u};
                pair<int,int>pr1;
                pr1=dfs1(u, 1, v, weight);
                mp[pr1.first] = pr1.second;
            }
            if(mp.size()==1)
                cout<<0<<endl;
            else
            {
            auto it = mp.rbegin(); 
            ++it;
            cout << it->second << endl;
        }
        }
    }
    return 0;
}