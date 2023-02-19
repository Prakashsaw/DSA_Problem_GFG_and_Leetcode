/*
 Q_ID:- 99;
 Q_Name:- Recover Binary Search Tree
 Platform:- Leetcode;
 Difficulty:- Medium
 Q_description:- 
    You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were  swapped by mistake. Recover the tree without changing its structure.

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-2^31 <= Node.val <= 2^31 - 1
 */
class Solution {
public:

    // void restore(TreeNode *root, vector<int> &v) {
    //     if(root == NULL) return;
    //     restore(root->left, v);
    //     root->val = v.back();
    //     v.pop_back();
    //     restore(root->right, v);
    // }

    // void inorder(TreeNode *root, vector<int> &v) {
    //     if(root == NULL) return;
    //     inorder(root->left, v);
    //     v.push_back(root->val);
    //     inorder(root->right, v);
    // }

    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = new TreeNode(INT_MIN);

    void inorder(TreeNode *root) {
        if(root == NULL) return;
        inorder(root->left);
        //print root->val
        if(first == NULL && pre->val > root->val) {
            first = pre;
        }
        if(first != NULL && pre->val > root->val) {
            second = root;
        }
        pre = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        //Brute force by taking extra space
        //store all element into an array
        //then check that which one is greater than next swap
        //TC = O(NlogN)
        //SC = O(N)
        //vector<int> v;
        // inorder(root, v);
        // int n = v.size();
        // sort(v.begin(), v.end());
        // reverse(v.begin(), v.end());
        // restore(root, v);


        //second approach
        //by not taking any extra space inorder traversal 
        //TC = O(N)
        //SC = O(logN)// RECURSIVE Call stack
        // inorder(root);
        // //now swap first and second
        // swap(first->val, second->val);


        //Third approach
        //TC = O(N)
        //Expected SC = O(1)
        // "Morris" traversal - Iterative version of inorder traversal

        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* pre = new TreeNode(INT_MIN);

        TreeNode* temp = root;
        while(temp) {
            
        }

        

    }
};