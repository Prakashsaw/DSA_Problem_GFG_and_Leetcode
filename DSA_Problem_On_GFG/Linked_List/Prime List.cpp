/*
You are given the head of a linked list. You have to replace all the
 values of the nodes with the nearest prime number. If more than one
 prime number exists at an equal distance, choose the smallest one.
*/

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
    void fill_array_with_all_prime_sieveOfErastothenes(vector<bool> &prime) {
        prime[0] = false;
        prime[1] = false;
        
        int n = 100000;
        
        for(int i = 2; i*i <= n; i++) {
            if(prime[i]) {
                for(int j = i*i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
public:
    Node *primeList(Node *head){
        vector<bool> prime(100001, true);
        
        fill_array_with_all_prime_sieveOfErastothenes(prime);
        
        vector<int> only_all_prime;
        
        for(int i = 2; i < 100001; i++) {
            if(prime[i]) only_all_prime.push_back(i);
        }
        
        Node* temp = head;
        while(temp != NULL) {
            int data = temp->val;
            if(data == 1) {
                temp->val = 2;
            }
            else if(prime[data]) {
                temp->val = data;
            } else {
                int index = lower_bound(only_all_prime.begin(), only_all_prime.end(), data) - only_all_prime.begin();
                if(data - only_all_prime[index-1] <= only_all_prime[index]-data) {
                    temp->val = only_all_prime[index-1];
                } else if(data - only_all_prime[index-1] > only_all_prime[index]-data) {
                    temp->val = only_all_prime[index];
                }
            }
            temp = temp->next;
        }
        
        return head;
        //TC = O(N*log(logn))
        //sc = O(N)
    }
};
