#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll           long long
#define make_faster   ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb            push_back
#define mp(a,b)       push_back(make_pair((a),(b)))
#define sort(a)        sort((a).begin(), (a).end());
#define yes            cout<<"YES"<<endl;
#define no             cout<<"NO"<<endl;
#define nl             cout<<endl;
#define lb(a)          lower_bound(v.begin(),v.end(),(a))
#define upb(a)         upper_bound(v.begin(),v.end(),(a))

// typedef vector<long long>                   vi;
// typedef vector<pair<int,int>>               vp;
// typedef vector<double>                      vd;
// typedef vector<char>                        vc;
// typedef set<int>                            si;
// typedef set<char>                           sc;
// typedef unordered_set<int>                  usi;

int main(){

int n,q;cin>>n>>q;

 vector<int>v(n+1);
 for(int i=1;i<=n;i++)
  cin>>v[i];
vector<int>check(n+1,0);
  
  int cnt=0;
 for(int i=3;i<=n;i++)
 {
  if(v[i-2]>=v[i-1]>=v[i])
    check[i]=(++cnt);
 }

  
    
    while(q--)
    {
      int i,j;cin>>i>>j;
       int bads=check[j]-check[i-1];
       cout<<j-i+1-bads*3<<endl;
    }


}