#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define mp(a, b) push_back(make_pair((a), (b)))
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl cout << endl;

const int N = 2e5 + 5;
int dp[N];

int lis_dp(int n, vector<int>& v) {
    if (dp[n] != -1)
        return dp[n];

    dp[n] = 1;
    for (int i = 0; i < n; i++) {
        if (v[n] > v[i]) 
            dp[n] = max(dp[n], lis_dp(i, v) + 1);
    }
    return dp[n];
}

int32_t main() {
    make_faster
    int t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) 
            cin >> v[i];

        cout << lis_dp(n - 1, v) << endl; 
    }
}
