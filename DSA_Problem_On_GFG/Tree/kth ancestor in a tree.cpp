//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
/*
    Kth ancestor
    gfg
*/

bool solve(Node* root, int node, vector<int> &vec) {
    if(root == NULL) {
        return false;
    }
    
    vec.push_back(root->data);
    
    if(root->data == node) {
        return true;
    }
    if(solve(root->left, node, vec) || solve(root->right, node, vec)) return true;
    
    vec.pop_back();
    
    return false;
    
}
int kthAncestor(Node *root, int k, int node)
{   
    vector<int> vec;
    solve(root, node, vec);
    if(vec.size() <= k) return -1;
    return vec[vec.size() - 1 - k];
}
