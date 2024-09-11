class Solution {
public:
    bool isValid(int row, int col, char val, vector<vector<char>>& board){
        for (int i = 0; i < 9; i++){
            if (board[i][col] == val)
                return false;
        }
        for (int j = 0; j < 9; j++){
            if (board[row][j] == val)
                return false;
        }
        int subblock_row = (row/3)*3;
        int subblock_col = (col/3)*3;
        for (int i = subblock_row; i < subblock_row + 3; i++){
            for (int j = subblock_col; j < subblock_col + 3; j++){
                if (board[i][j] == val)
                    return false;
            }
        }
        return true;
    }
    bool backTrack(vector<vector<char>>& board){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.'){
                    for (char k = '1'; k <= '9'; k++){
                        if (isValid(i, j, k, board)){
                            board[i][j] = k;
                            if (backTrack(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backTrack(board);
    }
};