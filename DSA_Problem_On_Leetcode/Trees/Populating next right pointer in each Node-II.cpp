/*
Q_id:- 117.
Q_Name:- Populating Next Right Pointers in Each Node II.
Description:- 
    Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100
 

Follow-up:

You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/

class Solution {
public:
    Node* connect(Node* root) {
        // //Brute force approach
        // //using level order traversal
        // //use queue data structure
        // //TC = O(N)
        // //SC = O(N)
        // if(root == NULL) return root;
        // queue<Node*> q;
        // q.push(root);
        // while(!q.empty()) {
        //     int n = q.size();
        //     Node* temp = NULL;
        //     for(int i = 0; i < n; i++) {
        //         Node* front = q.front();
        //         q.pop();
        //         if(temp == NULL) {
        //             temp = front;
        //         } else {
        //             temp->next = front;
        //             temp = front;
        //         }

        //         if(front->left) {
        //             q.push(front->left);
        //         }
        //         if(front->right) {
        //             q.push(front->right);
        //         }

        //         temp->next = NULL;
        //     }
        // }
        // return root;


        //Optimized approach
        //TC = O(N)
        //SC = O(1)

        Node* head = root;
        while(head != NULL) {
            Node* dummy = new Node(0);
            Node* temp = dummy;
            while(head != NULL) {
                if(head->left != NULL) {
                    temp->next = head->left;
                    temp = temp->next;
                }
                if(head->right != NULL) {
                    temp->next = head->right;
                    temp = temp->next;
                }
                head = head->next;
            }
            head = dummy->next;
        }     
        return root;


    }
};