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

int32_t main() {
    make_faster
    int n;
    cin >> n;
    
    vector<int> v(n), sub;
    for (int i = 0; i < n; i++) 
        cin >> v[i];

    for (int x : v) {
        auto it = lower_bound(sub.begin(), sub.end(), x); 
        if (it == sub.end()) 
            sub.push_back(x); 
        else 
            *it = x; 
    }

    cout << sub.size() << endl; 
}
