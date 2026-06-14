class Solution {
public:
    vector<vector<int>>dir={
        {1,0},
        {0,-1},
        {0,1},
        {-1,0}
    };

    int solve(int row,int col,vector<vector<int>>&grid,int n,int m){
        if(row<0 || col<0 || row>=n ||col>=m || grid[row][col]==-1 || grid[row][col]==0)
        return 0;
        
        int ans=1;
        int temp=grid[row][col];
        grid[row][col]=-1;
        for(int k=0;k<4;k++){
            ans=max(ans,temp+solve(row+dir[k][0],col+dir[k][1],grid,n,m));
        }
        grid[row][col]=temp;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=-1e9;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solve(i,j,grid,n,m));
            }
        }

        return ans;
    }
};
