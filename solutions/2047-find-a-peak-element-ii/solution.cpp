class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l =0;
        int r=n-1;
        vector<int>ans;

        while(l<=r){
            int mid=(l+r)/2;
            
            auto max_num=max_element(mat[mid].begin(),mat[mid].end());
            int col=max_num-mat[mid].begin();

            int top= mid-1>=0 ? mat[mid-1][col] : -1;
            int bottom= mid+1<n ? mat[mid+1][col] :-1;

            if(mat[mid][col]>top && mat[mid][col]>bottom){
                
                ans.push_back(mid);
                ans.push_back(col);
                return ans;
            }
            else if( mat[mid][col]>top)
            l=mid+1;
            else{
                r=mid-1;
            }
            

        }
        return ans;
    }
};
