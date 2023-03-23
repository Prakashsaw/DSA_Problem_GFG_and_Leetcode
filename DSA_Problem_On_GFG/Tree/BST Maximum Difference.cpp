/*
Q_Name:- BST Maximum Difference.
Platform:- gfg
Difficulty:- Medium
Q_Description:- 
    You are given a Binary Search Tree and a target value. You must find the maximum difference between the sum of node data from root to target and from target to a child leaf node (target exclusive). Initially, you are at the root node.
Note: If the target node is not present in the tree then return -1.

Example 1:

Input:


Target = 20
Output: 10
Explanation: From root to target the sum of node data is 25 and from target to the children leaf nodes the sums of the node data are 15 and 22. So, the maximum difference will be (25-15) = 10.
Example 2:

Input:

Target = 50
Output: -1
Explanation: The target node is not present in the tree.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxDifferenceBST() which takes BST(you are given the root node of the BST ) and target as input, and returns an interger value as the required answer. If the target is not present in the BST then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(H), H - Height of the Tree.


Constraints:
1 <= n < 10^4
1 <= node.data < 10^5
1 <= target < 10^5
*/
class Solution{
    Node* isNodePresent(Node* root, int target) {
        if(root == NULL) return NULL;
        
        if(root->data == target) return root;
        
        else if(root->data > target) {
            return isNodePresent(root->left, target);
        } else {
            return isNodePresent(root->right, target);
        }
    }
    
    int rootToTargetSum_Function(Node* root, int target) {
        if(root == NULL) return 0;
        
        if(root->data == target) return 0;
        
        else if(root->data > target) {
            return root->data + rootToTargetSum_Function(root->left, target);
        } else {
            return root->data + rootToTargetSum_Function(root->right, target);
        }
    }
    
    int targetToLeafMinSum_function(Node* root) {
        if(root == NULL) return INT_MAX;
        
        int leftSum = targetToLeafMinSum_function(root->left);
        int rightSum = targetToLeafMinSum_function(root->right);
        
        int minRes = min(leftSum, rightSum);
        
        if(minRes == INT_MAX)
            return  root->data;
        else 
            return minRes + root->data;
    }
    
public:
    int maxDifferenceBST(Node *root,int target){
        Node* tergetNode = isNodePresent(root, target);
        
        if(tergetNode == NULL) return -1;
        
        int rootToTargetSum = rootToTargetSum_Function(root, target);
        
        int targetToLeafMinSum = targetToLeafMinSum_function(tergetNode)-target;
        
        return (rootToTargetSum - targetToLeafMinSum);
    }
};