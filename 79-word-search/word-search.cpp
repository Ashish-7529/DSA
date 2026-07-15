class Solution {
public:
    bool solve(int idx, int i, int j, vector<vector<char>>& board, string& word) {
        int n = board[0].size();
        int m = board.size();

        if (idx == word.size()) return true;

        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] == '$' ||
            board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        if (solve(idx + 1, i + 1, j, board, word)) return true;
        if (solve(idx + 1, i - 1, j, board, word)) return true;
        if (solve(idx + 1, i, j + 1, board, word)) return true;
        if (solve(idx + 1, i, j - 1, board, word)) return true;

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && solve(0, i, j, board, word))
                    return true;
            }
        }

        return false;
    }
};