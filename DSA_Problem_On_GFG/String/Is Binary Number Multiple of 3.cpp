/*
Que:- Is Binary Number Multiple of 3
Level:-Medium
Companies:- Amazon,  Microsoft,  Adobe
Description:- 
    Given a number in its binary form find if the given binary number is a multiple of 3. It is recommended to finish the task using one traversal of input binary number.

Example 1:

Input: S = "0011"
Output: 1
Explanation: "0011" is 3, which is divisible by 3.
Example 2:

Input: S = "100"
Output: 0
Explanation: "100"'s decimal equivalent is 4, which is not divisible by 3.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function isDivisible() which takes the string s as inputs and returns 1 if the given number is divisible by 3 otherwise 0.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 10^5

*/
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int n = s.length();
	    
	    int x = 1, i = n-1;
	    long long int sum = 0;
	    
	    while(i >= 0) {
	        if(s[i]-'0' == 1) {
	            sum += x;
	        }
	        x = (x%3 * 2%3)%3;
	        i--;
	    }
	    if(sum % 3 == 0) return 1;
	    return 0;
	    
	    //TC = O(N)
	    //SC = O(1)
	}

};
