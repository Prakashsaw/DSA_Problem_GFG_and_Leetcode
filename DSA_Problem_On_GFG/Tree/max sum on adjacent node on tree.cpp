//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/*
Q_name: Max sum on Non-adjacent node in a Binary tree.
Platform:- GFG

Description:- 
    Given a binary tree with a value associated with each node, we need to choose 
    a subset of these nodes such that sum of chosen nodes is maximum under a 
    constraint that no two chosen node in subset should be directly connected 
    that is, if we have taken a node in our sum then we can’t take its any 
    children or parents in consideration and vice versa.

Constraints:- 
    1 ≤ Number of nodes in the tree ≤ 10000
    1 ≤ Value of each node ≤ 100000.
    
Logic:-  
    pair<int, int> == pair<max_sum_including_curr_node, max_sum_excluding_curr_node> 
    if(root == null) return {0, 0};
    
    updated first element t current node(include curr node in max sum) = 
        curr_node_ka_data + left_ka_ecluding + right_ka_excluding;
     
    updated second element at current node(exclude curr node in max sum) = 
        max(left_child_ka_including, left_child_ka_excluding) + max(right_child_ka_including, right_child_ka_excluding)
    
    //TC = O(N)
    //SC = O(H)
*/

class Solution{
    pair<int, int> solve(Node* root) {
        if(root == NULL) {
            return {0, 0};
        } 
        
        pair<int, int> left_ans = solve(root->left);
        pair<int, int> right_ans = solve(root->right);
        
        int first_ans = left_ans.second + right_ans.second + root->data;
        
        int second_ans = max(left_ans.first, left_ans.second) + max(right_ans.first, right_ans.second);
        
        return {first_ans, second_ans};
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};