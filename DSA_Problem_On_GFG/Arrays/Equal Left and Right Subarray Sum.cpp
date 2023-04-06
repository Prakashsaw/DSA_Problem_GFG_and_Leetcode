/*
Q_Name:- Equal Left and Right Subarray Sum
Platform:- gfg
Difficulty:- Easy
Description:- Given an array A of n positive numbers. The task is to find the first index in the array such that the sum of elements before it is equal to the sum of elements after it.

Note:  Array is 1-based indexed.

Example 1:

Input: 
n = 5 
A[] = {1,3,5,2,2} 
Output: 3 
Explanation: For second test case 
at position 3 elements before it 
(1+3) = elements after it (2+2). 
 

Example 2:

Input:
n = 1
A[] = {1}
Output: 1
Explanation:
Since its the only element hence
it is the only point.
Your Task:
The task is to complete the function equalSum() which takes the array and n as input parameters and returns the point. Return -1 if no such point exists.

Expected Time Complexily: O(N)
Expected Space Complexily: O(1)

Constraints:
1 <= n <= 10^6
1 <= A[i] <= 10^8
*/
class Solution {
  public:
    int equalSum(int n, vector<int> &arr) {
        //TC = O(N)
        //SC = O(1)
        int total = 0;
        for(int i = 0; i < n; i++) {
            total += arr[i];
        }
        
        int l_sum = 0, r_sum = 0;
        for(int i = 0; i < n; i++) {
            l_sum += arr[i];
            r_sum = total - l_sum + arr[i];
            
            if(l_sum == r_sum) return i+1;
        }
        
        return -1;
    }
};