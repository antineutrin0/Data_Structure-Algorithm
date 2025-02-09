#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const int MOD = 1e9 + 7;
#define set_precision(x) cout << fixed << setprecision(x);

// Loops
#define fo(i, a, b) for (int i = a; i < b; i++)
#define fo1(i, a, b) for (int i = a; i <= b; i++)
#define rof(i, a, b) for (int i = a; i >= b; i--)

// Min & Max
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))

// Pair, Vector
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>

// Binary Search, Lower Bound, Upper Bound
#define lb(v, x) (lower_bound(all(v), x) - v.begin())  // Lower Bound index
#define ub(v, x) (upper_bound(all(v), x) - v.begin())  // Upper Bound index
#define bs(v, x) (binary_search(all(v), x))            // Binary Search boolean

// Math Functions
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a / gcd(a, b)) * b)
#define mod_exp(base, exp, mod) ([](int base, int exp, int mod) { int res = 1; while (exp > 0) { if (exp % 2) res = (res * base) % mod; base = (base * base) % mod; exp /= 2; } return res; })(base, exp, mod)
#define modinv(a, m) mod_exp(a, m - 2, m)     

// Bit Manipulation
#define bitcount(x) __builtin_popcountll(x)   // Count set bits
#define tzcount(x) __builtin_ctzll(x)         // Trailing zeros
#define isPowerOfTwo(x) (x && !(x & (x - 1))) // Check power of 2

// Coordinate Compression
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())

// Fast Input/Output
#define print(v) for (auto x : v) cout << x << " "; cout << endl;

// Debugging
#define dbg(x) cerr << #x << " = " << (x) << endl;


void solve() {


}

int32_t main() {
    make_faster;
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
