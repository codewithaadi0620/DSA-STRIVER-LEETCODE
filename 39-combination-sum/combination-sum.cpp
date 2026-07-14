class Solution {
public:
void solve(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int idx,int target) {

        if (target==0) {
            ans.push_back(temp);
            return;
        }

        if(target<0 or idx>=nums.size()){
            return;
        }
        temp.push_back(nums[idx]);
        solve(ans, nums, temp, idx ,target-nums[idx]);

        
        temp.pop_back();
        solve(ans, nums, temp, idx + 1,target);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, candidates, temp, 0,target);

        return ans;
    }
};