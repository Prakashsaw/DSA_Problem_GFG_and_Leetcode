/*
 Q_ID:- 662.
 Q_NAME:- Maximum Width of Binary Tree.
 PLATFROM:-Leetcode.
 Difficulty:- Medium
Q_Description:- 
    Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        long long int ans = INT_MIN;
        while(!q.empty()) {

            int sz = q.size();
            long long int mn = q.front().second;
            long long int left_num, right_num;

            for(int i = 0; i < sz; i++) {
                auto front = q.front();
                q.pop();
                TreeNode* node = front.first;
                long long int num = front.second-mn;

                if(i == 0) {
                    left_num = num;
                }
                if(i == sz-1) {
                    right_num = num;
                }

                if(node->left) {
                    q.push({node->left, num*2+1});
                }
                if(node->right) {
                    q.push({node->right, num*2+2});
                }
            }

            ans = max(ans, right_num-left_num+1);
        }

        return ans;
    }
};