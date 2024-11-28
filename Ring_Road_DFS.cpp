#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
vector<pair<int,int>>g[N];

int dfs(int source,int firstnode, int node,vector<int>&vis,int wt)
{
    vis[node]=true;
    for(pair<int,int>v:g[node])
    {
        if(!vis[v.first]&&v.first!=source)
           {
            wt+=v.second+dfs(source,firstnode,v.first,vis,wt);
           }
           if(!vis[v.first]&&v.first==source&&firstnode!=node)
            return wt+=v.second;
          
    }
    return wt;

}

int main(){
    int n;cin>>n;
    vector<int>outdegree(n+1,0);
    for(int i=0;i<n;i++)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        outdegree[a]++;
        g[a].push_back({b,0});
        g[b].push_back({a,wt});
    }
    int ans=1e9;bool flg=0;
    for (int i = 1; i <=n; ++i)
    {
       

        if(outdegree[i]==2)
        for(pair<int,int> j:g[i]){
             flg=1;
             vector<int>vis(n+1,0);
           int res;
         res= dfs(i,j.first,j.first,vis,0);
         ans=min(ans,res);
        }

    }
    if(flg)
    cout<<ans<<endl;
else
    cout<<0<<endl;

    



}
