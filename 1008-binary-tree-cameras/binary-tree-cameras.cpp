/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans=0;
    int solve(TreeNode* node){
        if(!node) return 0;
            
        int left=solve(node->left);
        int right=solve(node->right);
        if(left==2 || right==2){
            ans++;
            return 1;
        }
        if(left==1 || right ==1 ){
            return 0;
        }
        return 2;
       
    }
public:
    int minCameraCover(TreeNode* root) {
        if(solve(root)==2){
            ans++;
        }
        return ans;
    }
};