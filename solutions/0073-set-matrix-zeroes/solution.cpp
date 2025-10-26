class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        vector<int>vec_row(row);
        vector<int>vec_col(col);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    vec_row[i]=1;
                    vec_col[j]=1;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vec_row[i] || vec_col[j]){
                    matrix[i][j]=0;
                }
            }
        }

    }
};
