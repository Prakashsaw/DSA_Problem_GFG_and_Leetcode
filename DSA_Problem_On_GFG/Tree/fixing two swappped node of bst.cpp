/*
Q_Name:- Fixing Two swapped nodes of a BST
platform:- gfg.
Difficulty:- HARD.
Q_Description:- 
    Two of the nodes of a Binary Search Tree (BST) are swapped. 
    Fix (or correct) the BST by swapping them back. 
    Do not change the structure of the tree.
    
Note: It is guaranteed than the given input will form BST, 
    except for 2 nodes that will be wrong.
    
Expected Time Complexity : O(Number of nodes)
Expected Auxiliary Space : O(logN), N = number of nodes
 
Constraints:
    1 <= Number of nodes <= 10^5

*/
class Solution {
    // void inorder_get(struct Node *root, vector<int> &v) {
    //     if(root == NULL) return ;
        
    //     inorder_get(root->left, v);
        
    //     v.push_back(root->data);
        
    //     inorder_get(root->right, v);
    // }
    
    // void inorder_restore(struct Node *root, vector<int> &v) {
    //     if(root == NULL) return;
        
    //     inorder_restore(root->left, v);
        
    //     root->data = v.back();
    //     v.pop_back();
        
    //     inorder_restore(root->right, v);
    // }
    
    
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *prev = new Node(INT_MIN);
    
    void inorder(struct Node *root) {
        if(root == NULL) return;
        
        inorder(root->left);
        
        //print value
        if(first == NULL && prev->data > root->data) {
            first = prev;
        }
        if(first != NULL && prev->data > root->data) {
            second = root;
        }
        prev = root;
        
        inorder(root->right);
    }
  public:
    struct Node *correctBST(struct Node *root) {
        // //brute force
        // //by taking extra space
        // //TC = O(NlogN)
        // //SC = O(N)
        // vector<int> v;
        
        // inorder_get(root, v);
        
        // sort(v.begin(), v.end());
        // reverse(v.begin(), v.end());
        
        // inorder_restore(root, v);
        
        // return root;
        
        
        
        //Second approach:- 
        //TC = O(N)
        //SC = O(H) recursive call stack
        inorder(root);
        swap(first->data, second->data);
        return root;
        
    }
};