class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && (i==0 || j==0 || i==n-1 ||j==m-1)) {
                    board[i][j] = 'T';
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k][0];
                int nc = c + dir[k][1];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;
                if (board[nr][nc] != 'O')
                    continue;

                board[nr][nc] = 'T';
                q.push({nr, nc});
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
