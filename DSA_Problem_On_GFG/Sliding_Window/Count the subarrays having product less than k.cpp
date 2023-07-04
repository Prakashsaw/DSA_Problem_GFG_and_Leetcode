/*
Count the subarrays having product less than k
Medium
Companies:- Goldman sache
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

Example 1:

Input : 
n = 4, k = 10
a[] = {1, 2, 3, 4}
Output : 
7
Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} 
{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
Example 2:

Input:
n = 7 , k = 100
a[] = {1, 9, 2, 8, 6, 4, 3}
Output:
16
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countSubArrayProductLessThanK() which takes the array a[], its size n and an integer k as inputs and returns the count of required subarrays.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<=n<=106
1<=k<=1015
1<=a[i]<=105


*/

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        //brute force
        // long long int ans = 0;
        // for(int i = 0; i < n; i++) {
        //     long long prod = 1;
        //     for(int j = i; j < n; j++) {
        //         prod *= arr[j];
        //         if(prod < 0) break;
        //         if(prod < k) {
        //             //cout << prod << " ";
        //             ans++;
        //         }
        //     }
        // }
        // //cout << endl;
        // return (int)ans;
        // //TC = O(N^2)
        // //SC = (1)
        // //still accepted
        
        
        //Optimize it by sliding window approach
        int ans = 0;
        long long prod = 1;
        int i = 0, j = 0;
        while(j < n) {
            prod *= arr[j];
            while(i <= j && prod >= k) {
                prod /= arr[i];
                i++;
            }
            ans = ans + (j-i+1);
            j++;
        }
        return ans;
        //TC = O(N)
        //SC = O(1)
        
        
        
    }
};