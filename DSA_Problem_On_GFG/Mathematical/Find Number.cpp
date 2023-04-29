/*
Q_Name:- Find Number
Q_Description:- 
    Given an integer N, You need to find the Nth smallest number which only contains odd digits i.e. 1,3,5,7,9 means no even digits are allowed on that number (12 will not consider). For example, the starting numbers which only contain odd digits are 1,3,5,7,9,11,13,15,17,19,31,33,35 and so on.

Example 1:

Input:
N=3
Output:
5
Explanation:
First three numbers are 1, 3, 5.
Here 5 is the 3rd number, where contains
only odd digits.
Example 2:

Input:
N=13
Output:
35
Explanation:
First 13 numbers are 1,3,5,7,9,
11,13,15,17,19,31,33,35, here 35 
is the answer.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findNumber() which takes a single variable N and returns the smallest Nth number which only contains odd digits.

Expected Time Complexity: O(logN)
Expected Space Complexity: O(1)

Constraints:
1 <= N <= 10^12
*/
class Solution{
public:

    // bool isValidNum(long long int num) {
        
    //     while(num > 0) {
    //         int digit = num%10;
    //         if(digit%2 == 0) return false;
            
    //         num /= 10;
    //     }
        
    //     return true;
    // }

    long long findNumber(long long n){
        // //Brute force appraoch
        // //TC >= O(N*12) run till n should be 10^6
        // //SC = O(1)
        // //Status:- TLE
        
        // int i = 1;
        // while(n) {
        //     if(isValidNum(i)) {
        //         n--;
        //     }
        //     i++;
        // }
        // return i-1;
        
        
        //Optimize approach
        long long int curr = 1;
        long long int ans = 0;
        int arr[] = {9, 1, 3, 5, 7};
        
        while(n) {
            ans += arr[n%5] * curr;
            
            if(n%5 == 0) {
                n = n/5-1;
            } else {
                n = n/5;
            }
            
            curr = curr*10;
        }
        
        return ans;
        
        //TC = O(logN) WITH base 5
        //SC = O(1)
    }
};