/*
 Q_id:- 530.
 Q_Name:- Minimum Absolute Difference in BST
 Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
 */
class Solution {
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
    int getMinimumDifference(TreeNode* root) {
        //without space 
        //TC = O(N)
        //SC = O(H) Recursive call stack
        solve(root);
        return ans;
    }
};