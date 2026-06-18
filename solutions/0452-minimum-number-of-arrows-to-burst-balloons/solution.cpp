class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](const vector<int> &a, const vector<int>&b){
            return a[1]<b[1];
        });
        
        int remove_count=0;

        int lastValidEnd=points[0][1];

        for(int i=1;i<points.size();i++){
            if(points[i][0]<=lastValidEnd){
                remove_count++;
                }
                else{
                    lastValidEnd=points[i][1];
                }
        }
        
        return n-remove_count;
    }
};
