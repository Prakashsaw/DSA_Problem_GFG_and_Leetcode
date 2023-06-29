/*
Que:- Next Happy Number
Level:- Hard
Description:- 
    For a given non-negative integer N, find the next smallest Happy Number. A number is called Happy if it leads to 1 after a sequence of steps. Wherein at each step the number is replaced by the sum of squares of its digits that is, if we start with Happy Number and keep replacing it with sum of squares of its digits, we reach 1 at some point.
 
Example 1:

Input:
N = 8
Output:
10
Explanation:
Next happy number after 8 is 10 since
1*1 + 0*0 = 1
Example 2:

Input:
N = 10
Output
13
Explanation:
After 10, 13 is the smallest happy number because
1*1 + 3*3 = 10, so we replace 13 by 10 and 1*1 + 0*0 = 1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function nextHappy() which takes an integer N as input parameters and returns an integer, next Happy number after N.

Expected Time Complexity: O(Nlog10N)
Expected Space Complexity: O(1)
 
Constraints:
1<=N<=10^5
*/

class Solution{
public:

    bool isValidHappyNumber(int n) {
        
        if(n < 10) {
            if(n == 1 || n == 7) return true;
            return false;
        }

        int num = 0;
        while(n) {
            num += (n%10)*(n%10);
            n /= 10;
        }
        return isValidHappyNumber(num);
        
        // while(1) {
        //     int temp = 0;
        //     int num = n;
        //     while(num) {
        //         int digit = num%10;
        //         num /= 10;
        //         temp += digit*digit;
        //     }
        //     if(temp == 1 || temp == 7) return true;
        //     if(temp < 10) break; 
        //     n = temp;
        // }
        // return false;
    }
    int nextHappy(int N){
        // code here
        //Brute force
        int ans = 0;
        int i = N+1;
        while(1) {
            if(isValidHappyNumber(i)) return i;
            i++;
        } 
        return 0;
        
        //TC = O(Nlog10(N))
        //SC = O(1) if we use iterative method
        //SC = O(log10(N)) //if we use recusrive method
    }
};