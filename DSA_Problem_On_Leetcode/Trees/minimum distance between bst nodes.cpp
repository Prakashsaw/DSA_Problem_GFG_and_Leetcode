/*
 Q_id:- 783.
 Q_Name:- Minimum Distance Between BST Nodes.
 Description:- Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
0 <= Node.val <= 105
 

 */
class Solution {
    // void inorder(TreeNode* root, vector<int> &v) {

    //     if(root == NULL) return ;

    //     inorder(root->left, v);

    //     v.push_back(root->val);

    //     inorder(root->right, v);
    // }

    int ans = INT_MAX;
    pair<int, int> solve(TreeNode* root){
        if(root == NULL) {
            return {INT_MAX, INT_MIN};
        }

        auto left_ans = solve(root->left);
        auto right_ans = solve(root->right);

        int x = left_ans.second;
        int y = right_ans.first;

        int diff1 = (x != INT_MIN) ? root->val-x : INT_MAX;
        int diff2 = (y != INT_MAX) ? y-root->val : INT_MAX;

        ans = min({ans, diff1, diff2});

        int mn = min(left_ans.first, root->val);
        int mx = max(root->val, right_ans.second);

        return {mn, mx};
    }
public:
    int minDiffInBST(TreeNode* root) {
        // //brute force
        // //by taking extras space
        // //TC = O(N)
        // //SC = O(N)
        // vector<int> v;
        // inorder(root, v);
        // int ans = INT_MAX;
        // int n = v.size();
        // for(int i = 0; i < n; i++) {
        //     int diff = (i+1 < n) ? v[i+1]-v[i] : INT_MAX;
        //     ans = min(ans, diff);
        // }
        // return ans;

        //without space 
        //TC = O(N)
        //SC = O(H) Recursive call stack
        solve(root);
        return ans;
    }
};