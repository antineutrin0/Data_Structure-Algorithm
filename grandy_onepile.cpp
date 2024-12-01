#include <bits/stdc++.h>
using namespace std;
int Mx=2e7+5;
vector<int>divisors(Mx,0);
vector<int> grandy_value(Mx, -1);

void divisorcount(){
    for(int i=1;i<=Mx;i++)
    {
        for(int j=i;j<=Mx;j+=i)
            divisors[j]++;
    }
}

int grandy(int piles,int move) {
    if (move == 0)
        return 0; 
    cout<<grandy_value[piles]<<" ";
    
    if (grandy_value[piles] != -1)
        return grandy_value[piles]; 
      
    set<int> reachable_grundy;
    for(int i=1;i<=move;i++)
    {
        reachable_grundy.insert(grandy(piles - i,divisors[piles-i]));
    }

    int mex = 0;
    while (reachable_grundy.count(mex))
    ++mex;
 
    return grandy_value[piles] = mex; 
}

int main() {

            divisorcount();
    int t;
    cin >> t; 
    while (t--) {
        int pile_size;
        cin >> pile_size; 
        int result = grandy(pile_size,divisors[pile_size]);

        if (result != 0)
            cout << "First player wins\n";
        else
            cout << "Second player wins\n";
    }
    return 0;
}
