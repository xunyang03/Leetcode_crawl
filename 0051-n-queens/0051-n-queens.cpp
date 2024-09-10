class Solution {
private:
    vector<vector<string>> result;
    vector<string> chessboard;
    unordered_set<int> occupied_col;
    unordered_set<int> occupied_diag1; // 45 deg
    unordered_set<int> occupied_diag2; // 135 deg

public:
    void processRow(int row, int n) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }

        string currentrow(n, '.'); // current row
        for (int col = 0; col < n; col++) {
            if (occupied_col.find(col) != occupied_col.end() ||
                occupied_diag1.find(row - col) != occupied_diag1.end() ||
                occupied_diag2.find(row + col) != occupied_diag2.end())
                continue;
            currentrow[col] = 'Q';
            occupied_col.insert(col);
            occupied_diag1.insert(row - col);
            occupied_diag2.insert(row + col);
            chessboard.push_back(currentrow);
            processRow(row + 1, n);
            chessboard.pop_back();
            occupied_diag1.erase(row - col);
            occupied_diag2.erase(row + col);
            occupied_col.erase(col);
            currentrow[col] = '.';
        }

        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        processRow(0, n);
        return result;
    }
};