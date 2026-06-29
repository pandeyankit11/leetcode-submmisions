class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int time=0;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                freshCount++;
                else if(grid[i][j]==2){
                vis[i][j]=1;
                q.push({i,j});
                }
                
            }
        }

        while(!q.empty()){
           int layerSize=q.size();

           for(int i=0;i<layerSize;i++){
            int r=q.front().first;
            int c=q.front().second;

            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dir[k][0];
                int nc=c+dir[k][1];

                if(nr<0 || nc<0 || nr>=n || nc>=m)
                continue;
                if(vis[nr][nc]==1)
                continue;
                if(grid[nr][nc]==0 || grid[nr][nc]==2)
                continue;

                freshCount--;
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
           }

           if(!q.empty())
           time++;
        }

        if(freshCount>0) return -1;

        return time;


    }
};
