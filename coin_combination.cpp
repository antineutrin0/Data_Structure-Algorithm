#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl cout << endl;

const int N = 1e6 + 5;
vector<int> dp(N,0); 

int32_t main() {
    make_faster;
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1; 
    int mod=1e9+7;

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j-coins[i]>=0)
                dp[j]+=dp[j-coins[i]];
            dp[j]%=mod;


        }
    }
    cout<<dp[x]<<endl;


    return 0;
}
