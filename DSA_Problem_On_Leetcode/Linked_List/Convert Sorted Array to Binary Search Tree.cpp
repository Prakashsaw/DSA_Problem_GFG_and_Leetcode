/*
 Q_Id:- 108
 Q_Name:- Convert Sorted Array to Binary Search Tree.
 Platform:- Leetcode.
 Difficulty:- Easy
 Q_Description:- 
    Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

Constraints:

1 <= nums.length <= 10^4
-104 <= nums[i] <= 10^4
nums is sorted in a strictly increasing order.
 */
class Solution {
    TreeNode* solve(vector<int> &v, int s, int e) {
        if(s > e) {
            return NULL;
        }

        if(s == e) {
            return new TreeNode(v[s]);
        }

        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(v[mid]);

        TreeNode* leftRootNode = solve(v, s, mid-1);
        TreeNode* rightRootNode = solve(v, mid+1, e);

        root->left = leftRootNode;
        root->right = rightRootNode;

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
        //TC = O(N)
        //SC = O(1)
    }
};