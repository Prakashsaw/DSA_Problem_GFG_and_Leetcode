 /*
 113. Path Sum II
 Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
 */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int targetSum, vector<int> path) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(targetSum-root->val == 0) {
                path.push_back(root->val);
                ans.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        dfs(root->left, targetSum-root->val, path);
        dfs(root->right, targetSum-root->val, path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);// using dfs to traverse on each node
        return ans;
    }
};