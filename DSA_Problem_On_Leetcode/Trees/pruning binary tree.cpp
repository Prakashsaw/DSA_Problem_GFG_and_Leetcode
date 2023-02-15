/*
 Q_ID:- 814.
 Q_Name:- Binary Tree Pruning
 Leetcode
 Medium
 Description:- 
    Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.
Constraints:- 
    The number of nodes in the tree is in the range [1, 200].
    Node.val is either 0 or 1.
 */
class Solution {
public:
    bool helper(TreeNode* root) {
        if(root == NULL) {
            return false;
        }
        bool leftAns = helper(root->left);
        bool rightAns = helper(root->right);
        if(leftAns == false) {
            delete root->left;
            root->left = NULL;
        }
        if(rightAns == false) {
            delete root->right;
            root->right = NULL;
        }
        if(leftAns == false && rightAns == false && (root->val == 0)) {
            return false;
        }
        return true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        bool leftans = helper(root->left);
        bool rightAns = helper(root->right);
        if(leftans == false) {
            delete root->left;
            root->left = NULL;
        }
        if(rightAns == false) {
            delete root->right;
            root->right = NULL;
        }
        if(leftans == NULL && rightAns == NULL && root->val == 0) {
            delete root;
            return NULL;
        }
        return root;
    }
};