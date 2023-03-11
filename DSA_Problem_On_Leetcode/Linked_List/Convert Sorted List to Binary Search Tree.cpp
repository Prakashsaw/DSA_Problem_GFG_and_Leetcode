/*
 Q_Id:- 109.
 Q_Name:- Convert Sorted List to Binary Search Tree.
 Platform:- Leetcode
 Difficulty:- Medium.
 Q_Description:- 
    Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 

Constraints:

The number of nodes in head is in the range [0, 2 * 104].
-10^5 <= Node.val <= 10^5
 */

ListNode* getMid(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode *slow = head, *fast = head;
    ListNode* prev = head;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return slow;
}
class Solution {
    TreeNode* solve(ListNode* head) {

        if(head == NULL) return NULL;

        if(head->next == NULL) {
            return new TreeNode(head->val);
        }

        ListNode* mid = getMid(head);

        TreeNode* root = new TreeNode(mid->val);

        TreeNode* leftRootNode = solve(head);
        TreeNode* rightRootNode = solve(mid->next);

        root->left = leftRootNode;
        root->right = rightRootNode;

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //brute force
        //approach is to convert given list into array and apply the concept of
        //convert sorted array into balanced BST
        //TC = O(N)
        //SC = O(N)


        //Another appraoch using divide and conquer in linked list.
        //TC = O(N)
        //SC = O(1)


        if(head == NULL) return NULL;

        // vector<int> v;

        ListNode* temp = head;

        // while(temp) {
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }

        // int s = 0;
        // int e = v.size()-1;

        
        return solve(temp);

       
    }
};