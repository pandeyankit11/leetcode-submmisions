class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>dupliNums(nums.begin(),nums.end());
        stack<int>st;
        dupliNums.insert(dupliNums.end(),nums.begin(),nums.end());
        vector<int>nge(dupliNums.size());
        int n=dupliNums.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=dupliNums[i]){
            st.pop();
            }

            if(st.empty()) 
            nge[i]=-1;
            else{
                nge[i]=st.top();
            }
            st.push(dupliNums[i]);
        }
        vector<int>finalNGE(nge.begin(),nge.begin()+(n/2));
        return finalNGE;
        
    }
};
