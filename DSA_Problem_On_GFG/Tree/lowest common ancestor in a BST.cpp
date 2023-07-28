//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* solve(Node* root, int n1, int n2) {
            if(root == NULL) return NULL;
            
            //if root is itself one of them
            //then in that case root is ans
            if((root->data == n1 || root->data == n2) || (root->data > n1 && root->data < n2) || (root->data > n2 && root->data < n1)) {
                return root;
            }
            
            if(root->data > n1 && root->data > n2) {
                //means LCS exist in left of the tree
                return solve(root->left, n1, n2);
            }
            
            if(root->data < n1 && root->data < n2) {
                //means LCS exist in right side of the tree
                return solve(root->right, n1, n2);
            }
            
        }
        Node* LCA(Node *root, int n1, int n2)
        {
            return solve(root, n1, n2);
            //TC = O(H)
            //SC = O(H)
        }

};