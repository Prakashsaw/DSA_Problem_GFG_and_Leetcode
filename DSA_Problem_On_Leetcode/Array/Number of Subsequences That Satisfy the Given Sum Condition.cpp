/*
Q_Id:- 1498.
Q_Name:- Number of Subsequences That Satisfy the Given Sum Condition.

Difficulty:- Medium
Description:-  
    You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= target <= 10^6
*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        /*
        Approach:-
            -> If there are n elements then total permutation that can be made is 2 raise to power n
            means we have to n options that we can take or not.

            -> If we calculate pow(2, n) bu using inbult in cpp then this will give TLE so for this 
            we can use extra vector to pre calculate pow in ith element where i is the no of elements
            
            -> sort that given array elements.
            -> use two pointer method i = 0, j = n-1;
            -> fix ith element as min then check which jth element(as max) satisfy condition that min + max <= target.
            -> if yes then calculate total element in that window 
            -> ans += precal[total_element];

            -> also do modulo by 1e9+7 parellely

            return ans.
        */


        int mod = 1e9+7;
        int n = nums.size();
        vector<int> p(n, 1);
        for(int i = 1; i < n; i++) {
            p[i] = (2*p[i-1]) % mod;
        }

        sort(nums.begin(), nums.end());
        
        int ans = 0;

        int i = 0;
        int j = n-1;

        while(i <= j) {
            if( (nums[i] + nums[j]) <= target) {
                int total_elements = j-i;
                ans  = (ans%mod + p[total_elements]%mod)%mod;
                i++;
            } else {
                j--;
            }
        }
        
        return ans;

        //TC = O(N + NlogN) = O(NlogN)
        //SC = O(N)
    }
};