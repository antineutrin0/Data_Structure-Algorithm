#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

vector<int> getLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    vector<int> tails;       // Stores smallest possible tail values
    vector<int> prev_indices; // Stores indices of elements in tails
    vector<int> parent(n, -1); // Parent pointers for reconstruction

    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        // Find position using binary search
        auto it = lower_bound(tails.begin(), tails.end(), num);
        int pos = it - tails.begin();

        // Set parent pointer
        if (pos > 0) {
            parent[i] = prev_indices[pos - 1];
        }

        // Update tails and prev_indices
        if (it == tails.end()) {
            tails.push_back(num);
            prev_indices.push_back(i);
        } else {
            *it = num;
            prev_indices[pos] = i;
        }
    }

    // Reconstruct the LIS from parent pointers
    vector<int> lis;
    int current = prev_indices.back();
    while (current != -1) {
        lis.push_back(nums[current]);
        current = parent[current];
    }
    reverse(lis.begin(), lis.end());
    
    return lis;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> result = getLIS(nums);
    
    cout << "Length of LIS: " << result.size() << endl;
    cout << "Subsequence: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;  // Output: 2 5 7 101 or similar valid LIS
    
    return 0;
}
