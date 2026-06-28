class Solution {
public:
     vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    bool dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis){
     vis[r][c]=1;

     bool closed=true;
     
     if(r==0 || c==0 || r==grid.size()-1 || c== grid[0].size()-1)
     closed=false;

     for(int k=0;k<4;k++){
        int nr=r+dir[k][0];
        int nc=c+dir[k][1];

            if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size())
            continue;
            if(grid[nr][nc]==1) 
            continue;
            if(vis[nr][nc]==1)
            continue;

            closed&=dfs(nr,nc,grid,vis);
     }

     return closed;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int closedIsland=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]==0){
                    if(dfs(i,j,grid,vis))
                    closedIsland++;
                }
            }
        }
        return closedIsland;
    }
};
