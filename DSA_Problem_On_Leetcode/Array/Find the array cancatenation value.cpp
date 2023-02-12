/*
Q_ID:- 2562.
Q_Name:- Find the Array Concatenation Value.
Difficulty:- Easy
Platform:- Leetcode.

Question:- 
-You are given a 0-indexed integer array nums.

The concatenation of two numbers is the number formed by concatenating their numerals.

For example, the concatenation of 15, 49 is 1549.
The concatenation value of nums is initially equal to 0. Perform this operation until nums becomes empty:

If there exists more than one number in nums, pick the first element and last element in nums respectively and add the value of their concatenation to the concatenation value of nums, then delete the first and last element from nums.
If one element exists, add its value to the concatenation value of nums, then delete it.
Return the concatenation value of the nums.

Constraints:- 
. 1 <= nums.length <= 1000
. 1 <= nums[i] <= 104
*/

class Solution {
public:
    int digitsof(int num) {
        int cnt = 0;
        while(num > 0) {
            cnt++;
            num = num / 10;
        }
        return cnt;
    }
    long long findTheArrayConcVal(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        long long sum = 0;
        
        while(i <= j) {
            if(i == j) {
                sum += nums[i];
                break;
            }
            int x = nums[i] * pow(10, digitsof(nums[j])) + nums[j];
            i++;
            j--;
            sum += x;
        }
        return sum;
    }
};