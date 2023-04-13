/*
Q_DESCRIPTION:- 
Q_Id:- 946.
Q_Name:- Validate Stack Sequences.
Platform:- Leetcode.
Difficulty:- Medium.
Q_DEscription:- 
    Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
All the elements of pushed are unique.
popped.length == pushed.length
popped is a permutation of pushed.
*/

/*
APPROACH:- 
    Some facts about given question:- 
    -Each distinct values.
    -Initial Empty stack.
    -Pooped is a permutation of pushed.
    Lengths are same.
    

    Now Move to the approach
    -first keep two pointer one in pushed arr and one is on popped arr.
    -take a empty stack.
    -iterate on pushed arr
    -push pushed[i] on stack st.
    -now aterate till st.top() == popped[j] arr
    -comming out of the loop and check that st is empty if yes then return true else return false;

    //TC = O(N)
    //SC = O(N)

*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int i = 0, j = 0;
        while(i < n) {
            st.push(pushed[i]);

            while(!st.empty() && j < n && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            i++;
        }

        if(st.empty()) return true;
        return false;
    }
};