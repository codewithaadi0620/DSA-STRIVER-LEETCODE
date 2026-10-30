class Solution {
public:
    // Helper function to find the path from root to the given node
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr) {
            return false;
        }
        
        // Add the current node to the path
        path.push_back(root);
        
        // If the target is found, return true
        if (root == target) {
            return true;
        }
        
        // Recursively check left and right subtrees
        if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
            return true;
        }
        
        // If target is not in the subtree, remove the node and return false
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        
        // Find paths from root to p and q
        findPath(root, p, path1);
        findPath(root, q, path2);
        
        TreeNode* lca = nullptr;
        
        // Traverse both paths and find the last matching node
        for (int i = 0; i < path1.size() && i < path2.size(); ++i) {
            if (path1[i] == path2[i]) {
                lca = path1[i];
            } else {
                break;
            }
        }
        
        return lca;
    }
};