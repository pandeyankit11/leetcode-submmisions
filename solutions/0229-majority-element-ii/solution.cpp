class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int el1=0,el2=0;
       int freq1=0,freq2=0;
       int limit=floor(nums.size()/3);
       vector<int>ans;
       for(int i=0;i<nums.size();i++){
        if(freq1==0 && nums[i]!=el2){
             el1=nums[i];
             freq1=1;
        }
        else if(freq2==0 && nums[i]!=el1){
            el2=nums[i];
            freq2=1;
        }

        else if(el1==nums[i]){
            freq1++;
        }
        else if(el2==nums[i]){
        freq2++;
        }
        else{
            freq1--;
            freq2--;
        }
    }

    int ans1=count(nums.begin(),nums.end(),el1);
    int ans2=count(nums.begin(),nums.end(),el2);

    if(ans1>limit) ans.push_back(el1);
    if(ans2>limit && el2!=el1) ans.push_back(el2);
    return ans;
    }
};
