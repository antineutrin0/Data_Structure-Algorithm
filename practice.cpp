#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

int32_t main() {
    make_faster;
    int t=1; 
   
    
    while (t--) {
        int n,m;cin>>n>>m;
        int ar[n+1][5];
     memset(ar,0,sizeof(ar));
     int j=0;
        for(int i=1;i<=m;i++){
           if(i<=2*n){
            ar[(i-1)/2][1]=i;
            if(i<m)
              { i++;
                ar[(i-1)/2][4]=i;
              }
           }
           else
           {
            ar[j][2]=i;
            if(i<m)
            {
              i++;
              ar[j][3]=i;
            }
            j++;
           }
        }

        for(int i=0;i<n;i++)
        { 
          
          if(ar[i][2]!=0)
            cout<<ar[i][2]<<" ";
          if(ar[i][1]!=0)
            cout<<ar[i][1]<<" ";
          if(ar[i][3]!=0)
            cout<<ar[i][3]<<" ";
          if(ar[i][4]!=0)
            cout<<ar[i][4]<<" ";
        }

    }
}
