class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {

        vector<int> pse(arr.size());

        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                pse[i] = -1;
            else {
                pse[i] = st.top();
            }

            st.push(i);
        }

        return pse;
    }
    vector<int> nextSmallerEle(vector<int>& arr) {

        vector<int> nse(arr.size());

        stack<int> st;

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = arr.size();
            else {
                nse[i] = st.top();
            }

            st.push(i);
        }

        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans=INT_MIN;

        vector<int>nse=nextSmallerEle(heights);
        vector<int>pse=prevSmaller(heights);

       for(int i=0;i<heights.size();i++){
          int left=pse[i];
          int right=nse[i];

          int width=right-left-1;
          ans=max(ans,width*heights[i]);
       }

       return ans;

    }
};
