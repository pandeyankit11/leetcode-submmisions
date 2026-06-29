class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (i==0 || j==0 || i==n-1 ||j==m-1)){
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dir[k][0];
                int nc=c+dir[k][1];

                if (nr < 0 || nc < 0 || nr >=n|| nc >=m)
                continue;
                if(grid[nr][nc]!=1)
                continue;

                grid[nr][nc]=0;
                q.push({nr,nc});
            }
        }

        int enclaves=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                enclaves++;
            }
        }
        return enclaves;
    }
};
