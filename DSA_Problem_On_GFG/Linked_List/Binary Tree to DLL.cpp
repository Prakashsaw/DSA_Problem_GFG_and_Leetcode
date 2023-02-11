/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
//Q Convert Binary Tree to Doubly Linked List(DLL)
//Difficulty:- HARD 
//TC = O(N)
//SC = O(H)
class Solution
{
    Node* head = NULL;
    Node* tail = NULL;
    void inorder(Node* root) {
        if(root == NULL) return ;
        
        inorder(root->left);
        
        if(head == NULL) {
            head = root;
            tail = root;
        } else {
            //This is like head->prev = node
            root->left = tail;
            //this is like head->next = node;
            tail->right = root;
            tail = root;
        }
        inorder(root->right);
        
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        inorder(root);
        return head;
    }
};