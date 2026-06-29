class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;

        int steps = 0;

        while (!q.empty()) {
            int layerSize = q.size();

            for (int i = 0; i < layerSize; i++) {
                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                if (maze[r][c] == '.' &&
                    (r == 0 || c == 0 || r == n - 1 || c == m - 1) &&
                    !(r == entrance[0] && c == entrance[1])) {
                    return steps;
                }

                for (int k = 0; k < 4; k++) {
                    int nr = r + dir[k][0];
                    int nc = c + dir[k][1];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;
                    if(vis[nr][nc]==1)
                    continue;
                    if(maze[nr][nc]=='+')
                    continue;

                    vis[nr][nc]=1;
                    q.push({nr,nc});    
                }
            }
            steps++;
        }

        return -1;
    }
};
