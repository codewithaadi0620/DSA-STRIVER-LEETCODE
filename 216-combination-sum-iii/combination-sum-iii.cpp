class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int start, int k, int target, vector<int>& curr) {
        // Valid combination
        if (k == 0) {
            if (target == 0) {
                ans.push_back(curr);
            }
            return;
        }

        // Target cannot be achieved
        if (target <= 0) {
            return;
        }

        // Try numbers from start to 9
        for (int i = start; i <= 9; i++) {
            // Since numbers are positive, no need to continue
            if (i > target)
                break;

            curr.push_back(i);

            // i+1 because each number can be used only once
            backtrack(i + 1, k - 1, target - i, curr);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(1, k, n, curr);
        return ans;
    }
};