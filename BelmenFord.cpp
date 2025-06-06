#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main(){
	int n,m;cin>>n>>m;
	vector<vector<int>>edges;

   for(int i=0;i<n;i++){
   	int u,v,w;cin>>u>>v>>w; 
   	edges.push_back({u,v,w});
   }
   
   vector<int>dist(n,INF);

  for(int i=0;i<n-1;i++ ){
   for(auto e:edges){
   	int u=e[0];
   	int v=e[1];
   	int w=e[2];
   	dist[v]=min(dist[v],dist[u]+w);
   }

  }

}