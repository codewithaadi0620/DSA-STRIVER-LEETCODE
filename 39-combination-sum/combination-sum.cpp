class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int> candidates, int target, int i, int sum,
               vector<int>& temp) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (sum > target || i >= candidates.size()) {
            return;
        }
        temp.push_back(candidates[i]);
        solve(candidates, target, i, sum + candidates[i], temp);
        temp.pop_back();
        solve(candidates, target, i + 1, sum, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, 0, 0, temp);
        return result;
    }
};