class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n<=2) return n; 
        int left=0;
        int max_len=INT_MIN;

        unordered_map<int,int>m;

        for(int right=0;right<fruits.size();right++){
            m[fruits[right]]++;

            while(m.size()>2){
                m[fruits[left]]--;
                if(m[fruits[left]] == 0) {
                    m.erase(fruits[left]);
                }

                left++;
            }

            max_len=max(max_len,right-left+1);
        }

        return max_len;
    }
};
