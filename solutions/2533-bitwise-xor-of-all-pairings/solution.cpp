class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        long long n=nums1.size();
        long long m=nums2.size();

        unordered_map<long long,long long>mp;
        for(int i=0;i<n;i++){
            mp[nums1[i]]+=m;
        }
        for(int i=0;i<m;i++){
            mp[nums2[i]]+=n;
        }

        int ans=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if((it->second)%2!=0){
                ans^=(it->first);
            }
        }
        return ans;
    }
};
