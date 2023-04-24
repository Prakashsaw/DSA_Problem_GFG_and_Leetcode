/*
Q_Id:- 2654.
Q_Name:-  Minimum Number of Operations to Make All Array Elements Equal to 1
Difficulty:- Medium
Description:- 
    You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:

Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

The gcd of two integers is the greatest common divisor of the two integers.

 

Example 1:

Input: nums = [2,6,3,4]
Output: 4
Explanation: We can do the following operations:
- Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
- Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
- Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
- Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
Example 2:

Input: nums = [2,10,6,14]
Output: -1
Explanation: It can be shown that it is impossible to make all the elements equal to 1.
 

Constraints:

2 <= nums.length <= 50
1 <= nums[i] <= 10^6
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) {
            if(nums[0] == 1) return 0;
            else return -1;
        }  
        int x = __gcd(nums[0], nums[1]);
        
        for(int i = 1; i < n; i++) {
            x = __gcd(x, nums[i]);
        }

        //not possible to make all element 1 return -1
        if(x > 1) return -1;

        int n1 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) n1++;
        }
        //if atleast one 1 be occure or exist in arr then ans should be total element - total ones;
        if(n1 == n) return 0;

        if(n1) return (n-n1);

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            int g = nums[i];
            for(int j = i+1; j < n; j++) {
                g = __gcd(g, nums[j]);
                if(g == 1) {
                    ans = min(ans, (j-i)+(n-1));
                }
            }
        }
        return ans;
    }
};