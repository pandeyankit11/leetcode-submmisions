class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        vector<int>ans(k);

        for(int i:nums){
            m[i]++;
        }

    vector<pair<int,int>> vec(m.begin(), m.end());

     sort(vec.begin(), vec.end(),[](pair<int,int> &a, pair<int,int> &b){
        return a.second > b.second;
    });
    for(int i=0;i<k;i++){
        ans[i]=vec[i].first;
    }
    return ans;


    }
};
