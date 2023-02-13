/*
Q_id:- 1523.
Q_Name:- Count Odd Numbers in an Interval Range.
Difficulty:- Easy
Leetcode.
Description:- 
    Given two non-negative integers low and high. 
    Return the count of odd numbers between low and high (inclusive).

Constraints:- 
    0 <= low <= high <= 10^9
*/
class Solution {
public:
    int countOdds(int low, int high) {
        
        if(low % 2 == 1) low -= 1;
        if(high % 2 == 1) high += 1;
        
        return (high/2 - low/2);
        //TC = O(1)
        //SC = O(1)
        
    }
};