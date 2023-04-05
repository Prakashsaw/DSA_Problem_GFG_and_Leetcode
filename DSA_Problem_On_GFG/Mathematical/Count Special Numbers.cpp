/*
GFG:-Count Special Numbers
Description:- 
    You are given an array arr[ ] of size N consisting of only positive integers. Your task is to find the count of special numbers in the array. A number is said to be a special number if it is divisible by at least 1 other element of the array.

Example 1:

Input:
N = 3
arr[] = {2, 3, 6}
Output:
1
Explanation:
The number 6 is the only special number in the
array as it is divisible by the array elements 2 
and 3. Hence, the answer is 1 in this case.
Example 2:

Input: 
N = 4
arr[] = {5, 5, 5, 5}
Output:
4
Explanation: 
All the array elements are special. Hence, 
the answer is 4 in this case.
Your Task:
You don't need to read input or print anything. Complete the function countSpecialNumbers() which takes the integer N and the array arr[ ] as the input parameters, and returns the count of special numbers in the array. 


Expected Time Complexity: O(N*M) where M = max(arr[i])
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 10^5 
1 ≤ arr[i] ≤ 10^6 
*/
class Solution {
    // bool isDivisible(int x, vector<int> &arr, int indx) {
    //     int n = arr.size();
    //     for(int i = 0; i < n; i++) {
    //         if(i != indx && (x % arr[i] == 0)) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        //Brute force
        //TC = O(N*N)
        //SC = O(1)
        
        // int ans = 0;
        // int e = n-1;
        // while(e >= 0) {
        //     if(isDivisible(arr[e], arr, e)) {
        //         ans++;
        //     }
        //     e--;
        // }
        // return ans;
        
        //Optimize approach
        //TC = O(N*logM)
        //SC = O(M)
        
        sort(arr.begin(), arr.end());
        
        int mx = arr[n-1];
        
        unordered_map<int, int> mp;
        
        vector<bool> sieve(mx+1, false);
        
        for(int i = 0; i < n; i++) {
            int x = arr[i];
            
            if(mp.count(x)) {
                mp[x]++;
                continue;
            }
            
            for(int j = 2*x; j <= mx; j += x) {
                sieve[j] = true;
            }
            
            mp[x]++;
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int x = arr[i];
            if(sieve[x] || mp[x] > 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
