#include <bits/stdc++.h>
using namespace std;

vector<int>prefix_array;

void prefix_fun(string str){

	int n=str.size();
	prefix_array.resize(n,0);

	for(int i=0;i<n;i++)
	{
		int j=prefix_array[i-1];

		while(j>0&&str[i]!=str[j])
			j=prefix_array[j-1];

		if(str[i]==str[j])
			j++;
		prefix_array[i]=j;

	}

}

int main(){
	string str,pattern;
	cin>>str>>pattern;
}
