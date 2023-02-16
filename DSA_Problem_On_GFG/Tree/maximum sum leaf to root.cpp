/*
Maximum sum leaf to root path
Given a Binary Tree, find the maximum sum path from a leaf to root.


Example 1:

Input:
        1
       / \
      2   3 
Output:
4
Explanation: 
Following the path 3 -> 1, results in a
sum of 4, which is the maximum path sum
from leaf to root for the given tree.
Example 2:

Input:
       10
      /  \
    -2    7
    / \   
   8  -4    
Output:
17
Explanation : 
Following the path 7 -> 10, results in a
sum of 17, which is the maximum path sum
from leaf to root for the given tree.

Your task :
You don't need to read input or print anything. Your task is to complete the function maxPathSum() which takes the root node of the tree as input and returns an integer denoting the maximum possible leaf to root path sum.

Expected Time Complexity: O(n) , where n = number of nodes
Expected Auxiliary Space: O(1)

Constraints : 
1 <= Number of nodes <= 10^5
-10^6 <= max sum path <= 10^6

*/
class Solution{
    int ans = INT_MIN;
    void solve(Node* root, int sum) {
        if(root == NULL) return ;
        
        sum += root->data;
        
        if(root->left == NULL && root->right == NULL) {
            ans = max(ans, sum);
        }
        
        solve(root->left, sum);
        solve(root->right, sum);
    }
    public:
    int maxPathSum(Node* root)
    {
        if(root == NULL) return 0;
        solve(root, 0);
        return ans;
    }
};