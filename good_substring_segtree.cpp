#include <bits/stdc++.h>
using namespace std;

int N = 1e5;
vector<int> v(N, 0);
vector<int> segmentTree(4 * N, 0);
vector<int> test_string(27, 0);

void build(int node, int start, int end, vector<int> &v, vector<int> &segmentTree) {
    if (start == end) {
        if (test_string[v[start]] == 0)
            segmentTree[node] = 1;
        else
            segmentTree[node] = 0;
    } else {
        int mid = (start + end) / 2;
        int leftchild = 2 * node + 1;
        int rightchild = 2 * node + 2;

        build(leftchild, start, mid, v, segmentTree);
        build(rightchild, mid + 1, end, v, segmentTree);
        segmentTree[node] = segmentTree[leftchild] + segmentTree[rightchild];
    }
}

int query(int node, int start, int end, int left, int right, vector<int> &segmentTree) {
    if (left > end || right < start) 
        return 0;
    if (left <= start && right >= end) 
        return segmentTree[node];

    int mid = (start + end) / 2;
    int leftchild = 2 * node + 1;
    int rightchild = 2 * node + 2;

    int leftsum = query(leftchild, start, mid, left, right, segmentTree);
    int rightsum = query(rightchild, mid + 1, end, left, right, segmentTree);
    return leftsum + rightsum;
}

int main() {
    int max_bad;
    string s, str;
    cin >> s >> str >> max_bad;
    int n = s.size();


    for (int i = 0; i < s.size(); i++) {
        v[i] = s[i] - 'a' + 1;
    }


    for (int i = 0; i < 26; i++) {
        if (str[i] == '1')
            test_string[i + 1] = 1;
    }


    build(0, 0, n - 1, v, segmentTree);

    int cnt = 0;
    set<string> st;
    map<pair<int,int>,string>mp_str;
   for (int i = 0; i < s.size(); i++) {        
    for (int j = i; j < s.size(); j++) {    
        mp_str[{i, j}] = s.substr(i, j - i + 1);
    }
} 

    for (int i = 0; i < s.size(); i++) {        
        for (int j = i; j < s.size(); j++) {    
            int result = query(0, 0, n - 1, i, j, segmentTree);
            if (result <= max_bad) {
                string substr=mp_str[{i,j}];
                st.insert(substr);
            }
        }
    }

    cout << st.size() << endl;

    return 0;
}
