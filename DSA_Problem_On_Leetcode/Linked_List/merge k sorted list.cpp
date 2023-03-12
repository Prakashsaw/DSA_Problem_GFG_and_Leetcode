/*
 Q_Id:- 23.
 Q_Name:- Merge k Sorted Lists.
 Platform:- Leetcode.
 Difficulty:- HARD
 Q_Description:- 
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
*/

class Solution {

    ListNode* getTail(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        while(head->next) {
            head = head->next;
        }
        return head;
    }

    ListNode* mergeTwoSortedLinkedList(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        //recursive
        if(l1->val <= l2->val) {
            l1->next = mergeTwoSortedLinkedList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLinkedList(l1, l2->next);
            return l2;
        }

        //iterative
        // ListNode *h = NULL, *t = NULL;
        // if(l1->val < l2->val) {
        //     h = l1;
        //     t = l1;
        //     l1 = l1->next;
        // }
        // else {
        //     h = l2;
        //     t = l2;
        //     l2 = l2->next;
        // }
        // while(l1 != NULL && l2 != NULL) {
        //     if(l1->val < l2->val) {
        //         t->next = l1;
        //         t = t->next;
        //         l1 = l1->next;
        //     }
        //     else {
        //         t->next = l2;
        //         t = t->next;
        //         l2 = l2->next;
        //     }
        // }
        // if(l1 == NULL) {
        //     t->next = l2;
        // }
        // else {
        //     t->next = l1;
        // }
        // return h;
    }


    //merge sort
    ListNode* getMid(ListNode* head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* mergeSort(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* midKaNext = mid->next;
        mid->next = NULL;
        ListNode* h1 = mergeSort(head);
        ListNode* h2 = mergeSort(midKaNext);
        return mergeTwoSortedLinkedList(h1, h2);
        
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //Brute force appraoach
        //first approach
        //taking all element into one array -> short them again make a list and terurn head of new list
        //let n = max of list[i] where 0 <= i <= 500;
        //TC = O((nk)(log(nk)))
        //SC = O(nk)
        // vector<int> v;
        // int k = lists.size();
        // for(int i = 0; i < k; i++) {
        //     ListNode* head = lists[i];
        //     while(head) {
        //         v.push_back(head->val);
        //         head = head->next;
        //     }
        // }
        // sort(v.begin(), v.end());
        // ListNode* ansHead = NULL;
        // ListNode* nextPtr = NULL;
        // for(int i = 0; i < v.size(); i++) {
        //     ListNode* newNode = new ListNode(v[i]);
        //     if(ansHead == NULL) {
        //         ansHead = newNode;
        //         nextPtr = newNode;
        //     } else {
        //         nextPtr -> next = newNode;
        //         nextPtr = newNode;
        //     }
        // }
        // return ansHead;


        //2.) Second appraoch
        //little bit optimize
        //Apply the approach of merge two sorted linked list
        //let n = max of list[i] where 0 <= i <= 500;
        //TC = O(nk)
        //SC = O(1)

        int k = lists.size();
        if(k == 0) return NULL;
        if(k == 1) return lists[0];
        ListNode* l1 = lists[0];
        for(int i = 1; i < k; i++) {
            l1 = mergeTwoSortedLinkedList(l1, lists[i]);
        }
        return l1;



        // //Third approach
        // //appraoch 
        // //connect all linked list and then apply the concept of merge sort on this linked list
        // //TC = O((nk)log(nk))+O(nk)
        // //SC = O(1)
        // int k = lists.size();
        // if(k == 0) return NULL;
        // if(k == 1) return lists[0];
        // ListNode* ansHead = NULL;
        // ListNode* preTail = NULL;
        // ListNode* tail = getTail(lists[0]);
        // if(tail != NULL) {
        //     preTail = tail;
        //     ansHead = lists[0];
        // }
        // for(int i = 1; i < k; i++) {
        //     if(preTail) {
        //         preTail->next = lists[i];
        //     }

        //     if(ansHead == NULL) ansHead = lists[i];

        //     tail = getTail(lists[i]);
        //     if(tail != NULL) {
        //         preTail = tail;
        //     }

        // }
        // //merge sort on this all connected list with head lists[0];
        // return  mergeSort(ansHead);
        

    }
};