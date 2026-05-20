class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        
        
        int left = 0;
        int count = 0;
        unordered_map<int, int> m;

        for (int right = 0; right < nums.size(); right++) {
           
            m[nums[right]]++;

           
            while (m.size() > k) {
                m[nums[left]]--;
                if (m[nums[left]] == 0) {
                    m.erase(nums[left]); 
                }
                left++; 
            }

            
            count += (right - left + 1);
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atMostK(nums,k)-atMostK(nums,k-1);
    }
};
