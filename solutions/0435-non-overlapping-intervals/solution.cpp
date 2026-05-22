class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if (n==1) return 0;
        vector<pair<int,int>>vec;
        int ans{0};
        for(int i=0;i<n;i++){
           vec.push_back({intervals[i][0],intervals[i][1]});
        }

      stable_sort(vec.begin(), vec.end(),
    [](const pair<int,int> &a,const pair<int,int> &b){

        return a.first < b.first;
    });
        int last_second=vec[0].second;
        for(int i=1;i<vec.size();i++){
            int curr_first=vec[i].first;
            int curr_second=vec[i].second;

            if(curr_first<last_second && curr_second<last_second){
                ans++;
                last_second=curr_second;
                
            }
            else if(curr_first<last_second){
                ans++;
            }
            else{
                last_second=curr_second;
            }

        }
        return ans;
    }
};
