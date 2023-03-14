/*
 Q_Id:- 129.
 Q_Name:- Sum Root to Leaf Numbers.
 Platform:- Leetcode
 Q_description:-
    You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.
 */
class Solution {
    void solve(TreeNode* root, int &sum, vector<int> &v) {
        if(root == NULL) return ;

        v.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {
            int num = 0;
            for(int i = 0; i < v.size(); i++) {
                num = num * 10 + v[i];
            }
            sum += num;
        }

        solve(root->left, sum, v);

        solve(root->right, sum,v);

        v.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        //brute force approach
        //store all digit in one path from root to leaf node into vector and if 
        //once reach to leaf node then find num and sum it to ans sum
        //TC = O(logN * logN)
        //SC = O(logN) + O(logN) One for recursive call stack and another for vector
        //which store path
        int sum = 0;
        vector<int> v;
        solve(root, sum, v);
        return sum;
    }
};