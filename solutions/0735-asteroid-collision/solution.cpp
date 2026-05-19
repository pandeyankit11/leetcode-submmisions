class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        

        for(int i=0;i<asteroids.size();i++){
            if(st.empty()) {
            st.push(asteroids[i]);
            continue;
            }
            if((st.top()>0 && asteroids[i]>0) || (st.top()<0 && asteroids[i]<0) || (st.top()<0 && asteroids[i]>0)){
            st.push(asteroids[i]);
            }
            else{
                if(abs(asteroids[i])>abs(st.top())){
                    st.pop();
                    
                    i--;
                }
                else if(abs(asteroids[i])==abs(st.top())){
                    st.pop();
                }
            
            }

        }
        vector<int>ans(st.size());
        for(int i=ans.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
