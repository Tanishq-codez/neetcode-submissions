class Solution {
public:
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};

    bool isvalid(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || j < 0 ||
            i >= board.size() ||
            j >= board[0].size())
            return false;

        return true;
    }

    bool backtrack(int l, int i, int j,
                   string& word,
                   vector<vector<char>>& board) {

        if (l == word.size())
            return true;

        for (int k = 0; k < 4; k++) {

            int ni = i + dx[k];
            int nj = j + dy[k];

            if (!isvalid(ni, nj, board))
                continue;

            if (word[l] != board[ni][nj])
                continue;

            // choose
            board[ni][nj] = '#';

            // explore
            if (backtrack(l + 1, ni, nj, word, board))
                return true;

            // undo
            board[ni][nj] = word[l];
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {

                if (word[0] == board[i][j]) {

                    
                    board[i][j] = '#';

                    if (backtrack(1, i, j, word, board))
                        return true;

                    
                    board[i][j] = word[0];
                }
            }
        }

        return false;
    }
};