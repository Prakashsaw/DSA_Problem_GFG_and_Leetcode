/*
Q_Name:- Smallest Positive missing number
Platform:- gfg
Difficulty:- Medium
Description:- 
    You are given an array arr[] of N integers including 0. 
    The task is to find the smallest positive number missing from the array.
    Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^6
-106 <= arr[i] <= 10^6

Companies:- Accolite, Amazon, Samsung, Snapdeal.
Topics:- Arrays, Searching, Data Structures and Algorithms.
*/
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // //brute force
        // //which firstly comes in my mind
        // sort(arr, arr+n);
        // int k = 1;
        // for(int i = 0; i < n; i++) {
        //     if(arr[i] == k) k++;
        // }
        // return k;
        // //TC = O(NlogN)
        // //SC = O(1)
        
        
        // //second approach
        // unordered_map<int, int> mp;
        // for(int i = 0; i < n; i++) {
        //     if(arr[i] > 0) mp[arr[i]] = 1;
        // }
        
        // int k = 1;
        // while(1) {
        //     if(mp.find(k) == mp.end()) break;
        //     k++;
        // }
        // return k;
        
        // //TC = O(N)
        // //SC = O(N)
        
        
        //Third approach and aptimize approach
        //modifies that given array
        bool isOnePresent = false;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 1) isOnePresent = true;
            
            if(arr[i] < 1) arr[i] = 1;
            
        }
        
        if(isOnePresent == false) return 1;
        
        for(int i = 0; i < n; i++) {
            arr[abs(arr[i]) - 1] = - abs(arr[abs(arr[i]) - 1]);
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) return i+1;
        }
        
        return n+1;
        
        //TC = O(N)
        //SC = O(1)
    } 
    
};