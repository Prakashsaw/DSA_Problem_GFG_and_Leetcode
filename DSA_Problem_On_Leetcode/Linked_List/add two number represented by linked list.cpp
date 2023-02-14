/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*
 Q_id:- 2.
 Q_Name:- Add Two number.
Platform:- Leetcode
Difficulty:- Medium
Description:- 
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in    reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Constraints:- 
    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
 */
class Solution {
public:

    // ListNode* reverseLinkedList(TreeNode* head) {
    //     if(head == NULL || head->next == NULL) return head; 

    //     ListNode* pre = NULL, *curr = NULL, *nextptr = NULL;
    //     curr = head;
    //     pre = NULL;
    //     while(curr != NULL) {
    //         nextptr = curr->next;
    //         curr->next = pre;
    //         pre = curr;
    //         curr = nextptr;
    //     }
    //     return pre;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        int sum = 0;
        ListNode* head = NULL;
        ListNode* currNode = NULL;
        while(l1 != NULL || l2 != NULL) {
            int currSum = 0;
            if(l1 != NULL) {
                currSum += l1->val;
                l1 = l1->next;
            } 
            if(l2 != NULL) {
                currSum += l2->val;
                l2 = l2->next;
            } 
            sum = (currSum + rem)%10;
            rem = (currSum + rem)/10;
            ListNode* newNode = new ListNode(sum);
            if(head == NULL) {
                head = newNode;
                currNode = newNode; 
            } else {
                currNode->next = newNode;
                currNode = newNode;
            }
        }
        if(rem != 0) {
            ListNode* newNode = new ListNode(rem);
            if(head == NULL) {
                head = newNode;
                currNode = newNode; 
            } else {
                currNode->next = newNode;
                currNode = newNode;
            }
        }
        return head;
    }
};