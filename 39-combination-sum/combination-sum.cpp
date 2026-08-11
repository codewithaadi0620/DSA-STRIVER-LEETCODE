class Solution {
public:
    vector<vector<int>> ans;
    void final(int i, int target, vector<int>& candidates, vector<int>& curr) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (i == candidates.size())
            return;
        // TAKE
        if (candidates[i] <= target) {
            curr.push_back(candidates[i]);
            final(i, target - candidates[i], candidates, curr);
            curr.pop_back();
        }

        // Not take
        final(i + 1, target, candidates, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        final(0, target, candidates, curr);
        return ans;
    }
};