/*
1493. Longest Subarray of 1's After Deleting One Element
Medium
Company:- Yandex
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        int ans = 0;
        while(j >= 0 && nums[j] == 0) j--;
        while(i < n && nums[i] == 0) i++;

        if(i > j) return 0;

        int k = i;
        int oneCnt = 0;
        bool isZeroOccure = false;
        while(k <= j) {
            if(nums[k] == 0) {
                oneCnt++;
                isZeroOccure = true;
            }
            if(oneCnt <= 1) {
                ans = max(ans, k-i+1);
                k++;
            } else {
                while(i <= k && oneCnt > 1) {
                    if(nums[i] == 0) oneCnt--;
                    i++;
                }
                k++;
            }
        }
        //if the case that all element be 1 then in that case also we have to remove one element
        if(ans == n) return ans-1;

        //if zero occure in between the longest 1's then longest subarray is including one zero s
        return isZeroOccure ? ans-1 : ans;

        //TC = O(N)
        //SC = O(1)
    }
};