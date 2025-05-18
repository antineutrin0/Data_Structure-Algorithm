#include <bits/stdc++.h>
using namespace std;

#define int long long
#define make_faster ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define nl cout << endl;

struct job {
    int id;
    int deadline;
    int profit;
};

// Comparator function to sort jobs in decreasing order of profit
bool cmp(job a, job b) {
    return a.profit > b.profit;
}

int32_t main() { 
    make_faster;
    int n;
    cin >> n;
    vector<job> jobs(n);
    
    for (int i = 0; i < n; i++) {
        int deadline, profit;
        cin >> deadline >> profit;
        jobs[i] = {i + 1, deadline, profit};
    }
    
    // Sort jobs by decreasing profit
    sort(jobs.begin(), jobs.end(), cmp);
    
    int max_deadline = 0;
    for (auto &j : jobs)
        max_deadline = max(max_deadline, j.deadline);
    
    vector<int> slot(max_deadline + 1, -1);
    int total_profit = 0, job_count = 0;
    
    for (auto &j : jobs) {
        for (int d = j.deadline; d > 0; d--) {
            if (slot[d] == -1) { // If slot is empty
                slot[d] = j.id;
                total_profit += j.profit;
                job_count++;
                break;
            }
        }
    }
    
    cout << "Max Profit: " << total_profit << "\n";
    cout << "Jobs Selected: ";
    for (int i = 1; i <= max_deadline; i++) {
        if (slot[i] != -1)
            cout << slot[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
