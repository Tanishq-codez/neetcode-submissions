class Solution {
public:
    
    bool isSafe(vector<string>& board, int n, int r, int c) {
        
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 'Q') return false;
        }

        for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

    
        for (int i = r-1, j = c+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void backtrack(vector<vector<string>>& ans, vector<string>& board, int n, int r) {
        
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (isSafe(board, n, r, c)) {
                
                board[r][c] = 'Q';     
                backtrack(ans, board, n, r + 1);
                board[r][c] = '.';    
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        backtrack(ans, board, n, 0);
        return ans;
    }
};