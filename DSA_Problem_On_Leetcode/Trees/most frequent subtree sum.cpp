/*
 Q_ID:- 508
 Q_Name:- Most Frequent Subtree Sum.
 Platform:- ;Leetcode
 Difficulty:- Medium
 
 Description:- 
    Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

Constraints:- 
    The number of nodes in the tree is in the range [1, 104].
    -10^5 <= Node.val <= 10^5
 */
class Solution {

    unordered_map<int, int> mp; //sum versus freq
    unordered_map<int, vector<int>> ans; //freq versus thier sum
    int max_freq = INT_MIN;

    int subtree_sum_la_kar_do(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left_subtree_sum = subtree_sum_la_kar_do(root->left);
        int right_subtree_sum = subtree_sum_la_kar_do(root->right);

        int current_sum = left_subtree_sum + right_subtree_sum + root->val;

        mp[current_sum]++;
        int curr_freq = mp[current_sum];

        ans[curr_freq].push_back(current_sum);

        max_freq = max(max_freq, mp[current_sum]);

        return current_sum;
        
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        int tree_sum = subtree_sum_la_kar_do(root);

        if(max_freq == INT_MIN) return {};

        return ans[max_freq];
        //TC = O(N)
        //SC = O(N)
    }
};