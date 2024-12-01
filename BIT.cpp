#include <stdc++.h>
using namespace std;

const int N=1e5;
vector<int>bit(N);
int n;

void updatesingle(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=(i&-i);
	}
}

int presum(int i)
{ int ans=0;
	while(i>0){
        ans+=bit[i];
        i-=(i&-i);
	}
	return ans;
}


int main(){

	cin>>n;

	


}