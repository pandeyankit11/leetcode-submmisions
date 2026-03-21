class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)
        return 1;
        
        int result=INT_MIN;
        for(int i=0;i<n;i++){
            unordered_map<double,int>m;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                double num=points[j][1]-points[i][1];
                double deno=points[j][0]-points[i][0];
                double theta =atan2(num,deno);
                m[theta]++;
                
            }
            int max_ele{0};
            for(auto it=m.begin();it!=m.end();it++){
             if(it->second > max_ele)
             max_ele=it->second;
            }
            result=max(result,max_ele+1);
        }
        return result;
    }
};
