/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
/*
Q_Name:- 
    Sum of the Longest Bloodline of a Tree 
    (Sum of nodes on the longest path from root to leaf node)?
Description:- 
    Given a binary tree of size N. Your task is to complete 
    the function sumOfLongRootToLeafPath(), that find the 
    sum of all nodes on the longest path from root to leaf node.
    If two or more paths compete for the longest path, then the 
    path having maximum sum of nodes is being considered.

Constraints:- 
    1 <= Number of nodes <= 10^4
    1 <= Data of a node <= 10^4
*/
class Solution
{
public:
    
    pair<int, int> maxPathDisAndSum(Node *root) {
        if(root == NULL ) {
            pair<int, int> ans;
            ans.first = 0;
            ans.second = 0;
            return ans;
        }
        pair<int, int> leftAns = maxPathDisAndSum(root->left);
        pair<int, int> rightAns = maxPathDisAndSum(root->right);
        
        int leftMaxPathDis = leftAns.first;
        int leftSum = leftAns.second;
        int rightMaxPathDis = rightAns.first;
        int rightSum = rightAns.second;
        
        int finalMaxPathDis, finalSum;
        if(leftMaxPathDis > rightMaxPathDis) {
            finalMaxPathDis = leftMaxPathDis + 1;
            finalSum = leftSum + root->data;
        }
        else if(leftMaxPathDis < rightMaxPathDis) {
            finalMaxPathDis = rightMaxPathDis + 1;
            finalSum = rightSum + root->data;
        }
        else {
            finalMaxPathDis = leftMaxPathDis + 1;
            finalSum = max(leftSum, rightSum) + root->data;
        }
        pair<int, int> ans;
        ans.first = finalMaxPathDis;
        ans.second = finalSum;
        return ans;
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        //TC = O(N), SC = O(H)
        pair<int, int> ans = maxPathDisAndSum(root);
        return ans.second;
        
    }
};