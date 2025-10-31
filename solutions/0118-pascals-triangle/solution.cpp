class Solution {
public:
    vector<int>generateRows(int N){
        long long res=1;
        vector<int>ans;
        ans.push_back(res);
        for(int col=1;col<N;col++){
            res*=N-col;
            res/=col;
            ans.push_back(res);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        for(int i=1;i<=numRows;i++){
            vec.push_back(generateRows(i));
        }
        return vec;
    }
};

