
/*
209. Minimum Size Subarray Sum
Medium
Companies:- Facebook-8
            Amazon-6
            Microsoft-4
            Bloomberg-2
            Goldman Sachs-2
            Google-2
            Apple-2
            Arcesium-2

Description:-
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // //brute force
        // int n = nums.size();
        // int ans = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for(int j = i; j < n; j++) {
        //         sum += nums[j];
        //         if(sum >= target) {
        //             ans = min(ans, j-i+1);
        //             break;
        //         }
        //     }
        // }
        // return ans==INT_MAX ? 0 : ans;

        // //TC = O(N^2)
        // //SC = O(1)
        // // Status:- TLE

        //Optimize approach
        //Sliding window approach
        int ans = INT_MAX;
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        while(j < n) {
            sum += nums[j];

            while(i <= j && sum >= target) {
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        } 
        return ans==INT_MAX ? 0 : ans;
        //TC = O(N)
        //SC = O(1)

        //Thinking another approch of binary search approach
        
        


    }
};