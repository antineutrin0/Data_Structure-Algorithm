#include <bits/stdc++.h>
using namespace std;

const int max_piles = 1e4;
vector<int> grandy_value(max_piles, -1);

int grandy(int move) {
    if (move == 0)
        return 0; 
    
    if (grandy_value[move] != -1)
        return grandy_value[move]; 
    
    set<int> reachable_grundy;
    if (move >= 1) reachable_grundy.insert(grandy(move - 1));
    if (move >= 2) reachable_grundy.insert(grandy(move - 2));
    if (move >= 3) reachable_grundy.insert(grandy(move - 3));

    int mex = 0;
    while (reachable_grundy.count(mex))
        ++mex;

    return grandy_value[move] = mex; 
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int pile_size;
        cin >> pile_size; 
        
        int result = grandy(pile_size);

        if (result != 0)
            cout << "First player wins\n";
        else
            cout << "Second player wins\n";
    }
    return 0;
}
