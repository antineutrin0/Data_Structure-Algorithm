#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes=5;
    queue<int>q;
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
   visited[0]=true;
   q.push(0);

   while(!q.empty()){
    int node=q.front();
    q.pop();
    cout<<node<<" ";
    for(int u:v[node])
    {
        if(!visited[u]){
            visited[u]=true;
            q.push(u);
        }

    }

   }
   



}