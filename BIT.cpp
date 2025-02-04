#include <bits/stdc++.h>
using namespace std;

void updatesingle(int i,int x,vector<int>&bit,int n)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=(i&-i);
	}
}

int presum(int i,vector<int>&bit,int n)
{ int ans=0;
	while(i>0){
        ans+=bit[i];
        i-=(i&-i);
	}
	return ans;
}


int main(){

	int t;cin>>t;
	while(t--)
	{
		int n,m;cin>>n>>m;
		vector<int>bit(n,0);
		while(m--){
			int a;cin>>a;
			if(a==0)
			{
				int i,j,val;cin>>i>>j>>val;
				updatesingle(i,val,bit,n);
				updatesingle(j+1,-val,bit,n);
			}
			else{
				int i,j;cin>>i>>j;
				int result=presum(j,bit,n)-presum(i-1,bit,n);
				cout<<result<<endl;

			}
		}

	}
	


}