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

    int n, maxWeight;
    cin >> n >> maxWeight;

    vector<int> weight(n, 0);
    vector<int> value(n, 0);
    multimap<int, int> mp;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        mp.insert({a, b}); 
    }

    int i = 0;
    for (auto it : mp) {
        weight[i] = it.first;
        value[i] = it.second;
        i++;
    }

    int maxValue = accumulate(value.begin(), value.end(), 0LL);
    
    vector<int> dp(maxValue + 1, 1e18); 
    dp[0] = 0; 

    for (int i = 0; i < n; ++i) {
        for (int v = maxValue; v >= value[i]; --v) {
            dp[v] = min(dp[v], dp[v - value[i]] + weight[i]);
        }
    }

   
    int result = 0;
    for (int v = 0; v <= maxValue; ++v) {
        if (dp[v] <= maxWeight) {
            result = v;
        }
    }

    cout << result << endl;

    return 0;
}
