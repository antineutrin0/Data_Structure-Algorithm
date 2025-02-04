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
    cin >> n >> w;

    vector<int> weight(n, 0);
    vector<int> v1, v2, v3;
    vector<pair<int, int>> value(n);
    multimap<int, pair<int, int>> mp;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v3.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        mp.insert({v1[i], {v2[i], v3[i]}});
    }

    int i = 0;
    for (auto it : mp) {
        weight[i] = it.first;
        value[i] = {it.second.first, it.second.second};
        i++;
    }

    int dp[w + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        int curWeight = weight[i];
        int curValue = value[i].first;
        int count = value[i].second;

        for (int b = 1; count > 0; b ++) {
            int batch = min(b, count);
            count -= batch;
            int batchWeight = curWeight * batch;
            int batchValue = curValue * batch;
            for (int j = w; j >= batchWeight; j--) {
                dp[j] = max(dp[j], dp[j - batchWeight] + batchValue);
            }
        }
    }

    cout << dp[w] << endl;
    return 0;
}
