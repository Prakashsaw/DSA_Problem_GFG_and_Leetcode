/*
Q_Id:- 540. 
Q_Name:- Single Element in a Sorted Array.
Q_description:- ou are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // //brute force
        // //do xor to all element
        // //TC = O(N)
        // //SC = O(1)
        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++) {
        //     ans = ans ^ nums[i];
        // }
        // return ans;

        //binary search method
        //TC = O(logN)
        //SC = O(1)

        //edge case.
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int s = 0;
        int e = n-1;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]) {
                return nums[mid];
            }
            if(mid%2 == 1) {
                if(nums[mid] == nums[mid-1]) {
                    s = mid+1;
                } else {
                    e = mid-1;
                }
            } else {
                if(nums[mid] == nums[mid-1]) {
                    e = mid-1;
                } else {
                    s = mid+1;
                }
            }
        }
        return -1;
    }
};