/*
Q_name:- Make the array beautiful.
Platform:- GFG.
Difficulty:- Easy
Q_Description:- 
    Given an array of positive and negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] have the same sign. And you can do the following operation any number of times until the array becomes beautiful.

If two adjacent integers have different signs, remove them.
Return the beautiful array after performing the above operation.

Note: An empty array is also a beautiful array. There can be many adjacent integers with different signs. So remove adjacent integers with different signs from left to right.

Example 1:

Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.
Example 2:

Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function makeBeautiful() which takes an array as an input parameter and returns an array.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)


Constraints:
1 <= size of the array <= 10^5
-10^5 <= arr[i] <= 10^5
 
*/

/*
Approach:
    -Take a stack.
    -start a loop from left to right.
    -if not element in stack then push arr[i] element.
    -if element present then check that element in top of stack and element arr[i]
    is of different sign.
    -if different sign then remove top of stack element and arr[i] elemeant as well.-
    -if not different sign then push arr[i] element in stack.
    
    -outside of loop push all element of stack into vector 
    -then reverse that vector and return ans vaector.
    
*/
class Solution {
    bool isDifferentSign(int x,int y) {
        if((x < 0 && y >= 0) || (x >= 0 && y < 0)) {
            return true;
        } 
        return false;
    }
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push(arr[i]);
            } else {
                if(isDifferentSign(st.top(), arr[i])) {
                    st.pop();
                } else {
                    st.push(arr[i]);
                }
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};