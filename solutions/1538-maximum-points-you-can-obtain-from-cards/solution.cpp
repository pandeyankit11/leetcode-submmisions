class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

       int total =accumulate(cardPoints.begin(),cardPoints.end(),0);
       
       int left=0;
       int min_sum=INT_MAX;
       int n=cardPoints.size();
       if(k==n) return total;

       int curr_window_sum=0;

       for(int right=0;right<n;right++){
        curr_window_sum+=cardPoints[right];

        if(right>=n-k-1){
            min_sum=min(min_sum,curr_window_sum);

            curr_window_sum -=cardPoints[left];
            left++;

        }
       }

       return total - min_sum;
    }
};
