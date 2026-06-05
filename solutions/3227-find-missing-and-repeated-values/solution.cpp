class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int row=grid.size();
        vector<int>ans(2);
        vector<int>checker(pow(row,2),0);

        for(int i=0;i<row;i++){
            for(int j=0;j<row;j++){
                checker[grid[i][j]-1]++;
            }
        }

        auto a=find(checker.begin(),checker.end(),2);
        auto b=find(checker.begin(),checker.end(),0);

        ans[0]=a-checker.begin()+1;
        ans[1]=b-checker.begin()+1;
        return ans;
    }
};
