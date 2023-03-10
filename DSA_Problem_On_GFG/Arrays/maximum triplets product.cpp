/*
Q_Name:- Maximum Triplet product.
Platform:- gfg
Difficulty:- Medium
Q_Description:- 
    Given an array arr of size n, the task is to find the maximum triplet product in the array.


Example 1:

Input:
n = 4
arr[] = {1, 2, 3, 5}
Output:
30
Explanation:
5*3*2 gives 30. This is the maximum possible
triplet product in the array.
Example 2:

Input:
n = 7
arr[] = {-3, -5, 1, 0, 8, 3, -2} 
Output:
120
Explanation: 
-3*-5*8 gives 120. This is the maximum possible triplet product in the array.

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxTripletProduct() which takes an integer n and an array arr and returns the maximum triplet product in the array.


Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)


Constraints:
3 ≤ N ≤ 5*10^5
-106 ≤ A[i] ≤ 10^6

*/
class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
        //TC = O(NlogN)
        //SC = O(1)
    	long long int ans = 1;
    	sort(arr, arr+n);
    	long long int fmx, smx, tmx, fmn, smn;
    	fmx = arr[n-1];
    	smx = arr[n-2];
    	tmx = arr[n-3];
    	fmn = arr[0];
    	smn = arr[1];
    	
    	return max(fmx*smx*tmx, fmx*fmn*smn);
    }
};