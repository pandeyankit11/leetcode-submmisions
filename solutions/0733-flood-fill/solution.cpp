class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    void dfs(int r, int c, vector<vector<int>> &image, int &startColor,int &color) {
        image[r][c]=color;

        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0];
            int nc = c + dir[k][1];

            if (nr < 0 || nc < 0 || nr >= image.size() || nc >= image[0].size())
            continue;
            if(image[nr][nc]!=startColor) 
            continue;
           
            dfs(nr,nc,image,startColor,color);    
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        if(image[sr][sc]==color) return image;
        int startColor=image[sr][sc];
        dfs(sr, sc, image,startColor,color);

        return image;
    }
};
