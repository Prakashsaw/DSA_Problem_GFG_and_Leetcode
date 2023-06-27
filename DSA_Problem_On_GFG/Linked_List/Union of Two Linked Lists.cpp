/*
struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/

/*
Union of Two Linked Lists
Easy

Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

Example 1:

Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 
Example 2:

Input:
L1 = 1->5->1->2->2->5
L2 = 4->5->6->7->1
Output: 
1 2 4 5 6 7
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output.
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

Expected Time Complexity: O((N+M)*Log(N+M))
Expected Auxiliary Space: O(N+M)

Constraints:
1<=N,M<=104
*/
class Solution
{
    public:
    
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merTwoSortedLinkedList(Node* l1, Node* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        Node* fhead = NULL;
        Node* ftail = NULL;
        if(l1->data > l2->data) {
            fhead = l2;
            ftail = l2;
            l2 = l2->next;
        } else {
            fhead = l1;
            ftail = l1;
            l1 = l1->next;
        }
        
        while(l1 && l2) {
            if(l1->data > l2->data) {
                ftail->next = l2;
                ftail = l2;
                l2 = l2->next;
            } else {
                ftail->next = l1;
                ftail = l1;
                l1 = l1->next;
            }
        }
        if(l1) {
            ftail->next = l1;
        } else {
            ftail->next = l2;
        }
        
        return fhead;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        //base case
        if(head == NULL || head->next == NULL) return head;
        
        Node* mid = getMid(head);
        Node* temp = mid->next;
        mid->next = NULL;
        
        //call recursively left 
        Node* l1 = mergeSort(head);
        
        //call recursively right
        Node* l2 = mergeSort(temp);
        
        //now merge these two sorted list and return the head
        return merTwoSortedLinkedList(l1, l2);
    }
    
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        //Brute force
        //taking an array stored all unique element and then sort then then make a list and return root;
        // set<int> st;
        // Node* t1 = head1;
        
        // while(t1) {
        //     st.insert(t1->data);
        //     t1 = t1->next;
        // }
        // t1 = head2;
        // while(t1) {
        //     st.insert(t1->data);
        //     t1 = t1->next;
        // }
        
        // Node* root = NULL, *nextNode = NULL;;
        // for(auto it = st.begin(); it != st.end(); ++it) {
        //     Node *currNode = new Node(*it);
            
        //     if(root == NULL) {
        //         root = currNode;
        //         nextNode = currNode;
        //     } else {
        //         nextNode->next = currNode;
        //         nextNode = currNode;
        //     }
        // }
        
        // return root;
        
        // //TC = O((M+N)log(M+N))
        // //SC = O(M+N)
        
        
        
        
        //Optimized approach
        //step:1- merge these two ll
        //step:2- sort this merged linked list
        //step:3- remove one less same consecutiive node from sorted linked list
        
        //finnaly return and node
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        
        Node* head = merTwoSortedLinkedList(head1, head2);
        
        
        //now remove consecutive same element with keeoing all unique element
        Node* temp = head;
        Node* pre = NULL, *curr = NULL, *nextNode = NULL;
        
        while(temp) {
            pre = temp;
            temp = temp->next;
            while(temp != NULL && temp->data == pre->data) {
                temp = temp->next;
            }
            pre->next = temp;
        }
        return head;
        
        //TC = O((M*N) log(M*N))
        //SC = O(1)
        
    }
};