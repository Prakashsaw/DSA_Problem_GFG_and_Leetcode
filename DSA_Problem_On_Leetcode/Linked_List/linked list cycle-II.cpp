/*
 Q_ID:- 142.
 Q_Name:- Linked List Cycle II.
 Platform:- Leetcode.

 Q_description:- 
    Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?

 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // //brute force
        // //Using map to store node 
        // //TC = O(N)
        // //SC = O(N)

        //base case
        // if(head == NULL || head->next == NULL) {
        //     return NULL;
        // }

        // unordered_map<ListNode*, bool> mp;
        // ListNode* temp = head;

        // while(temp) {
        //     if(mp.count(temp)) {
        //         return temp;
        //     }
        //     mp[temp] = true;
        //     temp = temp->next;
        // }

        // return NULL;


        //Lets us use slow and fast pointer method approach
        //Approach
        //first detect whether cycle or not
        //if cycle then slow and fast must be meet at the same node
        //if not then fast or fast->next will be null in that case return null
        //if cycle detect then next mudda is to find first cycle starting position of node
        // now one pointer start from head and another slow pointer and when both meet that will bw my ans

        //TC = O(N)
        //SC = O(1)

        //let us code this appraoch
        //base case
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                break;
            }
        }

        //if cycle not be exist
        if(slow != fast) {
            return NULL;
        }

        ListNode* pointer = head;

        while(pointer != slow) {
            pointer = pointer->next;
            slow = slow->next; 
        }

        return slow; //or pointer 
    }
};