class Solution {
public:
    vector<int> nse(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> NSE = nse(heights);
        vector<int> PSE = pse(heights);
        int maxi = 0;
        for (int i = 0; i < heights.size(); i++) {
            maxi = max(maxi, heights[i] * (NSE[i] - PSE[i] - 1));
        }
        return maxi;
    }
};