class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0],newInterval[1]});
        
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i][1]=max(intervals[i][1],intervals[i+1][1]);
                intervals.erase(i+1+intervals.begin());
                i--;
            }
        }

        return intervals;
    }
};
