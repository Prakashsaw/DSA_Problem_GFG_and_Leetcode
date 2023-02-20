/*
Q_Id:- 2566.
Q_Name:- Maximum Difference by Remapping a Digit.
Platform:- Leetcode
Difficulty:- Easy.
Description:- 
    You are given an integer num. You know that Danny Mittal will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Danny can make by remapping exactly one digit in num.

Notes:

When Danny remaps a digit d1 to another digit d2, Danny replaces all occurrences of d1 in num with d2.
Danny can remap a digit to itself, in which case num does not change.
Danny can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.
We mentioned "Danny Mittal" to congratulate him on being in the top 10 in Weekly Contest 326.
 

Example 1:

Input: num = 11891
Output: 99009
Explanation: 
To achieve the maximum value, Danny can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Danny can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
Example 2:

Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.
 

Constraints:

1 <= num <= 10^8
*/
class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> min_v;
        vector<int> max_v;
        while(num > 0) {
            min_v.push_back(num%10);
            max_v.push_back(num%10);
            num /= 10;
        }
        
        reverse(min_v.begin(), min_v.end());
        reverse(max_v.begin(), max_v.end());
        
        int change_digit = -1;
        for(int i = 0; i < max_v.size(); i++) {
            if(max_v[i] != 9) {
                change_digit = max_v[i];
                break;
            }
        }
        if(change_digit != -1) {
            //change all this digit to 9 in max_v
            for(int i = 0; i < max_v.size(); i++) {
                if(max_v[i] == change_digit) {
                    max_v[i] = 9;
                }
            }
        }
        
        int num1 = 0;
        for(int i = 0; i < max_v.size(); i++) {
            num1 = num1*10 + max_v[i];
        }
        
        change_digit = -1;
        for(int i = 0; i < min_v.size(); i++) {
            if(min_v[i] != 0) {
                change_digit = min_v[i];
                break;
            }
        }
        if(change_digit != -1) {
            //change all this digit to 9 in max_v
            for(int i = 0; i < min_v.size(); i++) {
                if(min_v[i] == change_digit) {
                    min_v[i] = 0;
                }
            }
        }
        int num2 = 0;
        for(int i = 0; i < min_v.size(); i++) {
            num2 = num2*10 + min_v[i];
        }
        
        return num1 - num2;
        //TC = O(N)
        //SC = O(8) = O(1)
        
    }
};