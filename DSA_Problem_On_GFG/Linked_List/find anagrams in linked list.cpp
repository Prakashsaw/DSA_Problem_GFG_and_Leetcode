/*
Q_Name:- Find anagrams in linked list.
platform:- gfg
difficulty:- Medium
Q_Description:- 
    Given a linked list of characters and a string S.
    Return all the anagrams of the string present in 
    the given linked list.In case of overlapping anagrams 
    choose the first anagram from left.
    
Example 1:

Input: a -> b -> c -> a -> d -> b -> c -> a
S = bac
Output: [a -> b -> c, b -> c -> a]
Explanation: In the given linked list,
there are three anagrams: 
1. a -> b -> c -> a -> d -> b -> c -> a
2. a -> b -> c -> a -> d -> b -> c -> a
3. a -> b -> c -> a -> d -> b -> c -> a
But in 1 and 2, a -> b -> c and b -> c-> a
are ovelapping.So we take a -> b -> c as it
comes first from left.So the output is:
[a->b->c,b->c->a]
Example 2:

Input: a -> b -> d -> c -> a
S = bac
Output: -1 
Explanation: There is no anagrams, so output is -1
Your Task:
You don't need to read input or print anything. Your task is to complete the function findAnagrams() which takes head node of the linked list and a string S as input parameters and returns an array of linked list which only stores starting point of the Anagram. If there is no anagram in the linked list,return -1.


Expected Time Complexity: O(N), where N is length of LinkedList
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 10^5
1 <= |S| <= 10^5
*/

class Solution {
    
    bool isAnagram(string a, string b){
        
        unordered_map<char, int> mp;
        for(int i = 0; i < a.length(); i++) {
            mp[a[i]]++;
        }
        for(int i = 0; i < b.length(); i++) {
            if(mp.find(b[i]) == mp.end()) {
                return false;
            }
            mp[b[i]]--;
            if(mp[b[i]] == 0) {
                mp.erase(b[i]);
            }
        }
        return true;
        
    }
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        /*
        Logic:- 
            Sliding window approach
            make s string str in linked lidt till their length not became equal to given string s
            now chech that both string is anagram or not
            see there are two cases here
            case-1:-
                if(anagram) then 
                store ith node into ans then
                move pointer i to curr node then
                make str to empty str = ""
                
                else not anagran
                then slide one char into ahead and ith pointer as well
                remove one char from left from str 
                
        TC = O(26*N)
        SC = O(26)
                
        */
        int n = s.length();
        Node* temp = head;
        Node* i = head;
        Node* prev = head;
        
        string str = "";
        
        vector<Node*> ans;
        
        while(temp) {
            str += temp->data;
            if(str.length() < n) {
                temp = temp->next;
            } else if(str.length() == n) {
                if(isAnagram(s, str)) {
                    prev = temp;
                    ans.push_back(i);
                    temp = temp->next;
                    prev->next = NULL;
                    i = temp;
                    str = "";
                } else {
                    str = str.substr(1);
                    temp = temp->next;
                    i = i->next;
                }
            }
        }
        return ans;
    }
};