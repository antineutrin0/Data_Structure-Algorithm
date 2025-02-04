#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl cout << endl;

const int N = 1e6 + 5;
vector<int> dp(N, INT_MAX); 

int32_t main() {
    make_faster;
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 0; 

    for (int i = 1; i <= x; i++) {
        for (int j=0;i<n;j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[x] == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << dp[x] << endl; 
    }

    return 0;
}
