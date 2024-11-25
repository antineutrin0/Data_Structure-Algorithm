#include <bits/stdc++.h>
using namespace std;
int N=1e5;
int INF=1e9;
vector<pair<int,int>>g[N];
vector<bool>vis;
vector<int>dist(N,INF);

void dijekstra(int source){

	set<pair<int,int>>q;
    dist[source]=0;
	q.insert({0,source});
	while(!q.empty()){
    auto node=*q.begin();
    int v=node.first;
    int v_dist=node.second;
    q.erase(q.begin());
    if(vis[v])
    	continue;
    vis[v]=1;
      for(auto child:g[v]){
      	int child_v=child.first;
      	int wt=child.second;
      	if(dist[v]+wt<dist[child_v])
      		{dist[child_v]=dist[v]+wt;
      	q.insert({dist[child_v],child_v});}
      }
    }

}

int main(){

 int n;cin>>n;
 for(int i=0;i<n;i++){
 	int x,y,wt;cin>>x>>y>>wt;
 	g[x].push_back({y,wt});
 }
	dijekstra(0);

}