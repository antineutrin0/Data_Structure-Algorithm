#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<vector<int>>> solutions;

void solve(int row, vector<vector<int>>& board, vector<int>& columns,
           vector<int>& diag1, vector<int>& diag2) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (columns[col] || diag1[row + col] || diag2[row - col + n - 1])
            continue;

        // Place queen as 1
        board[row][col] = 1;
        columns[col] = diag1[row + col] = diag2[row - col + n - 1] = 1;

        solve(row + 1, board, columns, diag1, diag2);

        // Backtrack
        board[row][col] = 0;
        columns[col] = diag1[row + col] = diag2[row - col + n - 1] = 0;
    }
}

int main() {
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> columns(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);

    solve(0, board, columns, diag1, diag2);

    cout << "Number of solutions: " << solutions.size() << "\n\n";

    for (const auto& sol : solutions) {
        for (const auto& row : sol) {
            for (int cell : row) cout << cell << " ";
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}
