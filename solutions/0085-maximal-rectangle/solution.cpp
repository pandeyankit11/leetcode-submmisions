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
        int ans = INT_MIN;

        vector<int> nse = nextSmallerEle(heights);
        vector<int> pse = prevSmaller(heights);

        for (int i = 0; i < heights.size(); i++) {
            int left = pse[i];
            int right = nse[i];

            int width = right - left - 1;
            ans = max(ans, width * heights[i]);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int max_area = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            max_area = max(max_area, largestRectangleArea(heights));
        }

        return max_area;
    }
};
