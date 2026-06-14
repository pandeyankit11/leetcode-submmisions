class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        
        int l = 1;
        int r = position[n - 1] - position[0]; 
        int ans = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            
           
            int ballsPlaced = 1;          
            int lastPlacedPos = position[0]; 
            
            for (int i = 1; i < n; i++) {
                
                if (position[i] - lastPlacedPos >= mid) {
                    ballsPlaced++;           
                    lastPlacedPos = position[i];
                }
            }
            
            
           
            if (ballsPlaced >= m) {
                ans = mid;     
                l = mid + 1;   
            } 
            else {
                r = mid - 1;   
            }
        }

        return ans;
    }
};
