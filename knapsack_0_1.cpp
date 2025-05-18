#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);

int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) { 
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
} 

int32_t main() {
    make_faster;
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << "Maximum Value: " << knapsack(W, wt, val, n) << "\n";
    return 0;
}
