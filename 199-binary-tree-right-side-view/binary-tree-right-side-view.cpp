/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void func(TreeNode* node, int level) {
        if (node == NULL)
            return;
        if (level == ans.size())
            ans.push_back(node->val);
        func(node->right, level + 1);
        func(node->left, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {

        int level = 0;
        func(root, level);
        return ans;
    }
};