class Solution {
public:


    int countLessOrEqual(vector<vector<int>>&matrix,int mid){
        int row=matrix.size()-1;
        int col=0;
        int count=0;
        while(row>=0 && col<matrix.size()){
            if(matrix[row][col]<=mid){
                count+=(row+1);
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0];
        int r=matrix[n-1][n-1];
        int ans=-1;

        while(l<=r){
            int mid=(l+r)/2;
            
            if(countLessOrEqual(matrix,mid)>=k){
                ans=mid;
            r=mid-1;
            }
            else{
                l=mid+1;
            }


        }
        return ans;
    }
};
