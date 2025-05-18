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
#define maxx(arr, n) (*std::max_element(arr, arr + n))
#define max_in_vector(vec) (*std::max_element(vec.begin(), vec.end()))

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

int modinv(int a){
	int res=1;
	int exp=MOD-2;
	while(exp){
		if(exp%2)
			res=(res*a)%MOD;
		res=(a*a)%MOD;
		exp/=2;
	}
	return res;
}


void solve() {
	int n;cin>>n;
    int l,r;cin>>l>>r;
	string s;cin>>s;
	vector<int>prehash(n,0);
	vector<int>pow31(n,1);
	int pr=1;
	int hash=0;
	for(int i=0;i<n;i++)
	{
		 if (i) pow31[i] = (pow31[i - 1] * 31) % MOD;
        hash = (hash + ((s[i] - 'a' + 1) * pow31[i]) % MOD) % MOD;
        prehash[i] = hash;
	}
	int result;
	if (l > 0) {
        result = (prehash[r] - prehash[l - 1] + MOD) % MOD;
        result = (result * modinv(pow31[l])) % MOD;
    }
    cout << "Hash of s[" << l << ".." << r << "] is: " << result << endl;
	
return;
}
int32_t main() {
    make_faster;
    int t=1;cin>>t;
    while (t--) {
        solve();
    }
}
