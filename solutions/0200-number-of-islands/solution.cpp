class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    void dfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        vis[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];

            if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size())
                continue;

            if (vis[nr][nc] == 1)
                continue;

            if (grid[nr][nc] == '0')
                continue;

            dfs(nr, nc, grid, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};
