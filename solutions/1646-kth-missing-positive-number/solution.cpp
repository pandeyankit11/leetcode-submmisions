class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>vec;

        for(int i=1;i<=arr[n-1]+k;i++){
            auto it=find(arr.begin(),arr.end(),i);
            if(it==arr.end()){
                vec.push_back(i);
            }
        }
        return vec[k-1];

    }
};
