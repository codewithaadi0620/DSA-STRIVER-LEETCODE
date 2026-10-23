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
    int maxi = 0;
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftSub = height(root->left);
        int rightSub = height(root->right);
        maxi = max(maxi, leftSub + rightSub);
        return 1 + max(leftSub, rightSub);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }
};