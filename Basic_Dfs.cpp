


#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>v[],vector<bool>&visited){
    visited[node]=true;
  cout<<node<<" ";
    for(int u:v[node]){
        if(!visited[u]){
            dfs(u,v,visited);
        }
    }

}

int main(){

    int nodes=5;
    vector<int>v[nodes];
    v[0].push_back(1);
    v[1].push_back(0);
    v[0].push_back(2);
    v[2].push_back(0);
    v[1].push_back(3);
    v[3].push_back(1);
    v[1].push_back(4);
    v[4].push_back(1);
  
   vector<bool>visited(nodes,false);

   dfs(0,v,visited);
   


}

