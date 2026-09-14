class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        // Build monotonic increasing stack
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }

            st.push(digit);
        }

        // If removals are still left, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Stack gives elements in reverse order
        string result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        // Remove leading zeroes
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }

        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};