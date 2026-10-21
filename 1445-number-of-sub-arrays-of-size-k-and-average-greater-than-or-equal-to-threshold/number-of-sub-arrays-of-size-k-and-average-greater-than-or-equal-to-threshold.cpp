class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int cnt = 0;

        // Construct the first window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        // Check the first window
        if (sum / k >= threshold) {
            cnt++;
        }

        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            sum = sum - arr[i - k] + arr[i];

            if (sum / k >= threshold) {
                cnt++;
            }
        }

        return cnt;
    }
};