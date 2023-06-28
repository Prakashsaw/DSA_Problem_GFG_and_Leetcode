/*
Que:- Serialize and Deserialize a Binary Tree
Level:- Medium
Companies :- Paytm Flipkart Accolite Amazon Microsoft MAQ Software Adobe Linkedin 
Quikr Yahoo InMobi
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to the tree and returns it.
Note: The structure of the tree must be maintained. Multiple nodes can have the same data.

Example 1:

Input:
      1
    /   \
   2     3
Output: 2 1 3
Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
Your Task:
The task is to complete two functions serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000
*/


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        if(root == NULL) return {};
        
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* Node = q.front();
            q.pop();
            
            if(Node == NULL) {
                ans.push_back(-1);
            } else {
                ans.push_back(Node->data);
            }
            
            if(Node != NULL) {
                q.push(Node->left);
                q.push(Node->right);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &arr)
    {
       //Your code here
       if(arr.size() == 0) return NULL;
       
       queue<Node*> q;
       int i = 0;
       Node* root = new Node(arr[0]);
       i++;
       q.push(root);
       
       while(!q.empty()) {
           Node* node = q.front();
           q.pop();
           
           Node *leftNode = NULL, *rightNode = NULL;
           
           //for left node
           int num = arr[i];
           i++;
           if(num != -1) {
               leftNode = new Node(num);
               q.push(leftNode);
           }
           
           //for right node
           num = arr[i];
           i++;
           if(num != -1) {
               rightNode = new Node(num);
               q.push(rightNode);
           }
           
           node->left = leftNode;
           node->right = rightNode;
           
       }
       
       return root;
       
       //TC = O(N)
       //SC = O(N)
    }

};