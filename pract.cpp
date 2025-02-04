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
  string s1,s2,s3;
  cin>>s1;
  cin>>s2;
  cin>>s3;

  map<char,int>mp;
  mp['A']=0;
  mp['B']=0;
  mp['C']=0;
  if(s1[1]=='>')
  	mp[s1[0]]++;
  if(s2[1]=='>')
  	mp[s2[0]]++;
  if(s3[1]=='>')
  	mp[s3[0]]++;
  if(s1[1]=='<')
  	mp[s1[2]]++;
  if(s2[1]=='<')
  	mp[s2[2]]++;
  if(s3[1]=='<')
  	mp[s3[2]]++;
  vector<pair<int,char>>vp;
   map<int,char>mp1;
   bool flg=1;
   for(auto it:mp){
    vp.push_back({it.second,it.first});
     if(it.second!=1)
     	flg=0;
   }
sort(vp);
if(flg)
	cout<<"Impossible"<<endl;
else
   {for(int i=0;i<vp.size();i++)
   	cout<<vp[i].second;
  cout<<endl;
   }
    



}