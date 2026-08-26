class Solution {
public:
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};

    bool isvalid(int i, int j, vector<vector<char>>& board) {
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    }

    bool backtrack(int l, int i, int j, string& word, vector<vector<char>>& board) {
        if (board[i][j] != word[l]) return false;
        if (l == word.size() - 1) return true;

        char tmp = board[i][j];
        board[i][j] = '#';

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (!isvalid(ni, nj, board)) continue;
            if (backtrack(l + 1, ni, nj, word, board)) {
                board[i][j] = tmp;
                return true;
            }
        }

        board[i][j] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (backtrack(0, i, j, word, board))
                    return true;
        return false;
    }
};