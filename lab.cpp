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
           int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        
        vector<int> tails;
        vector<int> lengths(n);
        
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            auto it = lower_bound(tails.begin(), tails.end(), num);
            int pos = it - tails.begin();
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
            lengths[i] = pos + 1;
        }
        
        int max_length = tails.size();
        vector<int> i;
        int current_length = max_length;
        int current_val = INT_MAX;
        
        for (int i = n - 1; i >= 0; --i) {
            if (lengths[i] == current_length && nums[i] < current_val) {
                i.push_back(i);
                current_val = nums[i];
                current_length--;
            }
        }
      int cnt=0; int ans=1;

       for(int i=0;i<max_length;i++)
       {   
         vector<int>dec;
           vector<int>rev;
         for(int k=n-1;k>=i[i];k--)
            rev.push_back(nums[k]);
         for(int j=0;j<rev.size();j++)
         {
             int num = rev[j];
            auto it = lower_bound(dec.begin(), dec.end(), num);
            int pos = it - dec.begin();
            if (it == dec.end()) {
                dec.push_back(num);
            } else {
                *it = num;
            }
         }
       if(dec.size()==max_length-cnt)
         {
            int siz=dec.size();
           ans=max(ans,2*siz-1);
         }
      cnt++;
       }
   
   cout<<ans<<endl;
 
return;
}
int32_t main() {
    make_faster;
    std::ifstream file("example.txt");
  char ch;
    while (!file.eof()) {
        solve();
    }
}
