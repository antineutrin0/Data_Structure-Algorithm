#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int>g[n];
	vector<int>indeg(n,0);
	for(int i=0;i<n;i++)
	{
		int a,b;cin>>a>>b;
		g[a].push_back(b);
		indeg[b]++;
	}

	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]==0)
		{
		q.push(i);
		}
	}

	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for(auto v:g[u])
		{
			indeg[v]--;
			if(indeg[v]==0)
				q.push(v);
		}
	}


}