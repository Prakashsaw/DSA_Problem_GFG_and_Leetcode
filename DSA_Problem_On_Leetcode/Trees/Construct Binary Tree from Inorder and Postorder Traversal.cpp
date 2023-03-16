/*
 Q_Id:- 106;
 Q_Name:- Construct Binary Tree from Inorder and Postorder Traversal
 Q_Description:- Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 
 */
class Solution {
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {

        if(inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int i;

        for(i = inStart; i <= inEnd; i++) {
            if(inorder[i] == root->val) break;
        }

        int inLeftSize = i-inStart;
        int inRightSize = inEnd-i;


        root->left = solve(inorder, postorder, inStart, i-1, postStart, inLeftSize+postStart-1);
        root->right = solve(inorder, postorder, i+1, inEnd, postEnd-inRightSize, postEnd-1);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();

        if(n == 0) return NULL;

        int inStart = 0;
        int inEnd = n-1;
        int postStart = 0;
        int postEnd = n-1;

        return solve(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }
};