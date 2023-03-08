/*
 Q_Id:- 2583.
 Q_name:- Kth Largest Sum in a Binary Tree.
 platform:- Leetcode.
 Difficulty:- Medium
 Q_Description:- 
    You are given the root of a binary tree and a positive integer k.

The level sum in the tree is the sum of the values of the nodes that are on the same level.

Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

Note that two nodes are on the same level if they have the same distance from the root.

 

Example 1:


Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
Example 2:


Input: root = [1,2,null,3], k = 1
Output: 3
Explanation: The largest level sum is 3.
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 10^5
1 <= Node.val <= 10^6
1 <= k <= n
 */
class Solution {
    void find_all_level_sum(TreeNode* root, vector<long long int> &res) {
        if(root == NULL) return ;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            long long int sum = 0;
            for(int i = 0; i < sz; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                
                sum += currNode->val;
                
                if(currNode->left) {
                    q.push(currNode->left);
                }
                if(currNode->right) {
                    q.push(currNode->right);
                }
            }
            res.push_back(sum);
        }
    }
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        //brute force
        //TC = O(N) + O(log(N)log(log(N)))
        //SC = O(log(N))
        
        vector<long long int> res;
        
        find_all_level_sum(root, res);
        
        if(k > res.size()) return -1;
        
        sort(res.begin(), res.end());
        
        reverse(res.begin(), res.end());
        
        return res[k-1];
    }
};