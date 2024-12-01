#include<bits/stdc++.h>
using namespace std;
const int N=1e5;int INF=1e9;
vector<pair<int,int>>g[N];
vector<int>dist(N,INF);
vector<bool>vis(N,false);

void dijekstra(int source){
	set<pair<int,int>>q;
	q.push({0,source});
	dist[source]=0;
	while(!q.empty()){
		auto node=*q.begin();
		int v=node.second;
		int v_dist=node.first;
		q.erase(q.begin());
		if(vis[v])
			continue;
		vis[v]=1;
		for(pair<int,int>child:g[v]){
			int child_v=child.first;
			int wt=child.second;
		    if(dist[v]+wt<dist[child_v])
		    {
               dist[child_v]=dist[v]+wt;
               q.insert({dist[child_v],child_v});
               
		    }
		}
	}

}


int main(){


}