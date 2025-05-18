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


void solve() {
	int n,e;cin>>n>>e;
   
	vector<vector<int>> graph(n);
    vector<bool>assigned(n,0);
	for(int i=0;i<e;i++)
	{
		int a,b;cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
    vector<int>set1;
    vector<int>set2;
    queue<int>q1,q2;
    q1.push(0);
    set1.push_back(0);
    assigned[0]=1;
    while(q1.size()>0||q2.size()>0){ 
    	if(q1.size()>0)
    	{
    		int node=q1.front();
    		q1.pop();
    		for(auto it:graph[node]){
    			if(!assigned[it])
    				{
    					q2.push(it);
    					assigned[it]=true;
    					set2.push_back(it);
    				}
    		}
    	}

    	if(q2.size()>0)
    	{
    		int node=q2.front();
    		q2.pop();
    		for(auto it:graph[node]){
    			if(!assigned[it])
    				{
    					q1.push(it);
    					assigned[it]=true;
    					set1.push_back(it);
    				}
    		}
    	}
    }
    print(set1);
    print(set2);
return;
}
int32_t main() {
    make_faster;
    int t=1;//cin>>t;
    while (t--) {
        solve();
    }
}
