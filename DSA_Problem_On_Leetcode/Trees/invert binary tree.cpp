/*
 Q_Id:- 226.
 Q_Name:- Invert Binary Tree.
 Platform:- Leetcode.
 Difficulty:- Easy.
 
 Q_Description:- Given the root of a binary tree, invert the tree, and return its root.

 Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        TreeNode* left_ans = invertTree(root->left);
        TreeNode* right_ans = invertTree(root->right);

        root->left = right_ans;
        root->right = left_ans;

        return root;
    }
};