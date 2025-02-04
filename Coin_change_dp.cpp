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
    int n, m;
    cin >> n >> m;

    vector<int> coins(m);
    for (int i = 0; i < m; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(),coins.end());

   int dp[m+1][n+1];
   memset(dp,0,sizeof(dp));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
        
            dp[i][j] = dp[i - 1][j];

            if (j >= coins[i - 1]) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    cout<<dp[m][n]<<endl;

    return 0;
}
