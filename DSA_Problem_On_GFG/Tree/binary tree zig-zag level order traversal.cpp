/*
 Q_Id:- 103.
 Q_Name:- Binary Tree Zigzag Level Order Traversal.
 Q_Description:- Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100.

 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //TC = O(N)
        //SC = O(N)
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        vector<int> v;

        queue<TreeNode*> q;

        q.push(root);

        bool odd_level = true;

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto curr_node = q.front();
                q.pop();

                v.push_back(curr_node->val);

                if(curr_node->left != NULL) {
                    q.push(curr_node->left);
                }

                if(curr_node->right != NULL) {
                    q.push(curr_node->right);
                }
            }
            if(odd_level) {
                ans.push_back(v);
                v.clear();
                odd_level = false;
            } else {
                reverse(v.begin(), v.end());
                ans.push_back(v);
                v.clear();
                odd_level = true;
            }
        }
        return ans;
    }
};