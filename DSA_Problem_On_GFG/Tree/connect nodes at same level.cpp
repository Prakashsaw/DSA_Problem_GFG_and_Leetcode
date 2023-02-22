/*
Q_Name:- Connect Nodes at Same Level.
Platform:- GFG
Difficulty:= Medium.

Q_Description:- 
    Given a binary tree, connect the nodes that are at the same level. The structure of the tree Node contains an addition nextRight pointer for this purpose.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

 

Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
       3 ------> NULL
     /   \
    1---> 2 -----> NULL
Example 2:

Input:
      10
    /   \
   20   30
  /  \
 40  60
Output:
10 20 30 40 60
40 20 60 10 30
Explanation:The connected tree is
        10 ---> NULL
       /   \
     20---> 30 ---> NULL
   /   \
 40---> 60 ---> NULL
Your Task:
You don't have to read input or print anything. Complete the function connect() that takes the root of the tree as  input parameter and connects the nodes that lie at the same level. 

Note: The generated output will contain 2 lines. First line contains the level order traversal of the tree and second line contains the inorder traversal of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ Number of nodes ≤ 10^5
0 ≤ Data of a node ≤ 10^5


*/

class Solution{
    public:
    void connect(Node *root)
    {
        // //first approach
        // //level order traversal with taking queue data structure
        // //TC = O(N)
        // //SC = O(N)
        // queue<Node*> q;
        // q.push(root);
        // while(!q.empty()) {
        //     int sz = q.size();
            
        //     Node* temp = NULL;
            
        //     for(int i = 0; i < sz; i++) {
        //         Node* curr = q.front();
        //         q.pop();
               
               
        //         if(temp == NULL) {
        //             temp = curr;
        //         } else {
        //             temp->nextRight = curr;
        //             temp = curr;
        //         }
               
        //         if(curr->left != NULL) {
        //             q.push(curr->left);
        //         }
        //         if(curr->right != NULL) {
        //             q.push(curr->right);
        //         }
        //     }
        // }
        
        
        //optimize appraoch
        //doing without extra space
        //TC = O(N)
        //SC = O(1)
        root->nextRight = NULL;
        Node* ans = root;
        while(root != NULL) {
            Node* dummy = newNode(0);
            Node* temp = dummy;
            while(root != NULL) {
                if(root->left != NULL) {
                    temp->nextRight = root->left;
                    temp = root->left;
                }
                if(root->right != NULL) {
                    temp->nextRight = root->right;
                    temp = root->right;
                }
                root = root->nextRight;
            }
            root = dummy->nextRight;
        }
    }    
};
