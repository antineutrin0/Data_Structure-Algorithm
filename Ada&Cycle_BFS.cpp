#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
vector<int>g[N];

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
             int a;cin>>a;
             if(a==1)
                g[i+1].push_back(j+1);

        }
    }
    vector<int>res(n+1,-1);
for(int i=1;i<=n;i++)
{
    vector<int>vis(n+1,0);
     vector<int>level(n+1,0);
     level[i]=1;
     queue<int>q;
     q.push(i);
    vis[i]=1;
    bool flg=0;
     while(!q.empty()){
        int u=q.front();
        q.pop();
         for(int v:g[u]){
            if(!vis[v])
                {q.push(v);vis[v]=1;level[v]=level[u]+1;}
            else if(vis[v]&&v==i)
            {   flg=1;
                res[i]=level[u];
                break;
            }
         }
         if(flg) break;

     } 

}

for (int i = 1; i <= n; ++i)
{ if(res[i]==-1)
cout<<"NO WAY"<<endl;
else
   cout<<res[i]<<endl;
}


}
