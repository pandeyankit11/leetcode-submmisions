class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        string ans="";
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int curr{0};
        int max_freq=INT_MIN;

        for(auto it=m.begin();it!=m.end();it++){
            curr=it->second;
            if(curr>max_freq)
            max_freq=curr;
        }

        for(int i=max_freq;i>0;i--){
            for(auto it=m.begin();it!=m.end();it++){
                if(i==it->second){
                    while(it->second>0){
                        ans+=it->first;
                        it->second--;
                    }
                }
            }
        }

        return ans;
    }
};
