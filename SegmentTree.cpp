#include<bits/stdc++.h>
using namespace std;
int N=1e5;
vector<int>v(N,0);
vector<int>segmentTree(4*N,0);


void build(int node,int start,int end,vector<int>&v,vector<int>&segmentTree){
	if(start==end)
	segmentTree[node]=v[start];
else{
	int mid=(start+end)/2;
	int leftchild=2*node+1;
	int rightchild=2*node+2;

   build(leftchild,start,mid,v,segmentTree);
   build(rightchild,mid+1,end,v,segmentTree);
   segmentTree[node]= segmentTree[leftchild]+segmentTree[rightchild];

  }

}
void update(int node,int start,int end,int i,int val,vector<int>&segmentTree){
        if(start==end){
        	segmentTree[node]=val;
        }
        else{
        	int mid=(start+end)/2;
        	int leftchild=2*node+1;
        	int rightchild=2*node+2;
        	if(i<=mid)
        	{
        		update(leftchild,start,mid,i,val,segmentTree);

        	}
        	else
        		update(rightchild,mid+1,end,i,val,segmentTree);

     segmentTree[node]=segmentTree[leftchild]+segmentTree[rightchild];
        }
}

int query(int node,int start,int end, int left,int right,vector<int>&segmentTree){
	if(left>end||right<start)
		return 0;
	if(left<=start&&right>=end)
	{
           return segmentTree[node];
	}

	int mid=(start+end)/2;
	int leftchild=2*node+1;
	int rightchild=2*node+2;

   int leftsum=query(leftchild,start,mid,left,right,segmentTree);
   int rightsum=query(rightchild,mid+1,end,left,right,segmentTree);
  return leftsum+rightsum;

}


int main() {
    // Input array
    int n; 
    cout << "Enter size of array: ";
    cin >> n;
    
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) cin >> v[i];

    // Build the Segment Tree
    build(0, 0, n - 1, v, segmentTree);

    // Perform queries and updates
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Query range sum\n";
        cout << "2. Update an element\n";
        cout << "3. Print Segment Tree\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int left, right;
            cout << "Enter range (0-based index) [left, right]: ";
            cin >> left >> right;

            int result = query(0, 0, n - 1, left, right, segmentTree);
            cout << "Range sum [" << left << ", " << right << "] = " << result << "\n";
        } 
        else if (choice == 2) {
            int i, val;
            cout << "Enter index to update and new value: ";
            cin >> i >> val;

            update(0, 0, n - 1, i, val, segmentTree);
            cout << "Updated element at index " << i << " to " << val << ".\n";
        } 
        else if (choice == 3) {
            cout << "Segment Tree content:\n";
            for (int i = 0; i < 4 * n; i++) {
                if (segmentTree[i] != 0)
                    cout << "Node " << i << ": " << segmentTree[i] << "\n";
            }
        } 
        else if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

