/*
Q_Id:- 41.
Q_Name:-  First Missing Positive
Difficulty:- 
    Hard
Description: -
    Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // //Brute force approach
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // int k = 1;

        // for(int i = 0; i < n; i++) {
        //     if(nums[i] == k) {
        //         k++;
        //     }
        // }
        // return k;
        // //TC = O(NlogN)
        // //SC = O(1)


        // //Second approach by using grequency array
        // unordered_map<int, int> mp;
        // int n = nums.size();
        // for(int i = 0; i < n; i++) {
        //     if(nums[i] > 0) {
        //         mp[nums[i]] = 1;
        //     }
        // }

        // int k = 1;
        // while(1) {
        //     if(mp.find(k) == mp.end()) {
        //         break;
        //     }
        //     k++;
        // }
        // return k;
        // //TC = O(N)
        // //SC = O(10^8)


        bool one = false;
        int n = nums.size();
        int i=0;
        for(i=0;i<n;i++)
        {
            if(nums[i] == 1) one = true;
            if(nums[i] < 1 || nums[i] > n) nums[i] = 1;    
        }
        if(one == false) return 1;
        for(i=0;i<n;i++)
        {
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        for(i=0;i<n;i++)
        {
            if(nums[i] > 0) return i+1;
        }
        return n+1;

        //TC = O(N)
        //SC = O(1)

        
    }
};