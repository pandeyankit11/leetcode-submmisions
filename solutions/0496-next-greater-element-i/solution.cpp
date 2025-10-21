class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;
        stack<int>st;
        map<int,int>m;
        vector<int>ans;

        for(int i=nums2.size()-1;i>=0;i--){
            auto it =find(nums1.begin(),nums1.end(),nums2[i]);
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(it!=nums1.end()){
                if(st.empty()) m[nums2[i]]=-1;
                else m[nums2[i]]=st.top();
            }
            st.push(nums2[i]);

        }
        for(int i=0;i<nums1.size();i++){
            for(auto it=m.begin();it!=m.end();it++){
                if(nums1[i]==it->first)
                ans.push_back(it->second);
            }
        }
        
        return ans;
        
    }
};
