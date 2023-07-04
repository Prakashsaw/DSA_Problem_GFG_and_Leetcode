
/*
137. Single Number II
Medium
Description:- 
    Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //brute force
        //Taking extra space
        int n = nums.size();
        if(n == 1) return nums[0];

        // unordered_map<int, int> mp;
        // for(int i = 0; i < n; i++) {
        //     mp[nums[i]]++;
        // }
        // for(auto x : mp) {
        //     if(x.second == 1) return x.first;
        // }
        // return 0;
        // //TC = O(N)
        // //SC = O(N)

        int ones = 0;
        int twos = 0;
        for(int i = 0; i < n; i++) {
            ones = (nums[i] ^ ones) & (~twos);
            twos = (nums[i] ^ twos) & (~ones);
        }
        return ones;
    }
};