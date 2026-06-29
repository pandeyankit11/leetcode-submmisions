class Solution {
public:

    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int layerSize = q.size();

            for (int i = 0; i < layerSize; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dir[k][0];
                    int nc = c + dir[k][1];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    if (dist[nr][nc] != -1)
                        continue;

                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};
