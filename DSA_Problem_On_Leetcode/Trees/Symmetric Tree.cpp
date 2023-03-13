/*
 101. Symmetric Tree.
 Q_Description:- 
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 */
class Solution {
private:
    bool dfs(TreeNode* p, TreeNode* q) {
        //Base case
        if(p == NULL && q == NULL) return true;

        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false; 

        bool l = dfs(p->left, q->right);
        if(l == false) return false;

        bool r = dfs(p->right, q->left);
        if(r == false) return false;

        return true;

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root->left, root->right);
        //TC = O(N)
        //SC = O(H)
    }
};