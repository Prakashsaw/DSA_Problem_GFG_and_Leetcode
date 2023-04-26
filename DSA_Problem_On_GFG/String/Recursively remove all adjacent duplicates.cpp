/*
Q_Name:- Recursively remove all adjacent duplicates
Given a string s, remove all its adjacent duplicate characters recursively. 

Note: For some test cases, the resultant string would be an empty string. In that case, the function should return the empty string only.

Example 1:

Input:
S = "geeksforgeek"
Output: "gksforgk"
Explanation: 
g(ee)ksforg(ee)k -> gksforgk

Example 2:

Input: 
S = "abccbccba"
Output: ""
Explanation: 
ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

Your Task:
You don't need to read input or print anything. Your task is to complete the function rremove() which takes the string S as input parameter and returns the resultant string.


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1<=|S|<=105
Company Tags:
    Paytm Samsung
Topic Tags:-
    Strings Recursion Data Structures Algorithms
*/
class Solution{
public:
    string rremove(string s){
        if(s.length() == 0) return "";
        
        string ans = "";
        bool duplicate = false;
        
        for(int i = 0; i < s.length(); i++) {
            if(i+1 < s.length() && s[i+1] == s[i]) {
                duplicate = true;
                while(i+1 < s.length() && s[i+1] == s[i]) {
                    i++;
                }
            } else {
                ans += s[i];
            }
        }
        
        if(duplicate) {
            return rremove(ans);
        }
        return s;
        
        /*
        The time complexity of this code can be calculated by analyzing 
        each operation and iteration performed in the code.

        The code iterates over each character of the input string s, 
        so the time complexity of the for loop is O(n) where n 
        is the length of the input string.
        
        The operations inside the for loop include checking if the 
        current character has a duplicate character following it, 
        and appending the current character to the ans string if it 
        does not have a duplicate. Both of these operations take constant 
        time, so they can be considered as O(1).
        
        The recursive call to rremove at the end of the function is 
        performed only if there were duplicates found in the input string.
        If the input string contains no duplicates, the function returns the 
        input string s. In the worst case scenario, the function needs to 
        be called recursively on every character of the input string, and 
        each recursive call is performed on a string that is half the length
        of the previous call. This results in a total of log(n) recursive calls, 
        with each call taking O(n) time. Therefore, the time complexity of the 
        recursive call is O(n log n).
        
        Putting all of these together, the time complexity of the code is O(n log n).


        */
        
        
    }
};