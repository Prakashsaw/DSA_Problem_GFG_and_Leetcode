/*
Q_Id:- 605
Q_Name:- Can Place Flowers
Q_Description:-
    You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

Constraints:

1 <= flowerbed.length <= 2 * 10^4
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        /*
        Simple approach
        find All possible position of placing plant and 
        check if position cnt is more or equal to n then return true else return false
        */
        //TC = O(N)
        //SC = O(1)

        int sz = flowerbed.size();
        
        //edge case 
        if(sz == 1) {
            if(flowerbed[0] == 0) {
                if(n <= 1) return true;
                else return false;
            } else {
                if(n == 0) return true;
                 else return false;
            }
        }

        int cnt = 0;

        for(int i = 0; i < sz; i++) {
            if(flowerbed[i] == 0) {
                if(i == 0) {
                    if(i+1 < sz && flowerbed[i+1] != 1) {
                        cnt++;
                        flowerbed[i] = 1;
                    } 
                } else if(i == sz-1) {
                    if(i-1 >= 0 && flowerbed[i-1] != 1) {
                        cnt++;
                        flowerbed[i] = 1;
                    }
                } else {
                    if(flowerbed[i-1] != 1 && flowerbed[i+1] != 1) {
                        cnt++;
                        flowerbed[i] = 1;
                    }
                }
                
            }
        }
        if(cnt >= n) return true;
        return false;

        // if (n == 0) {
        //     return true;
        // }
        // for (int i = 0; i < flowerbed.size(); i++) {
        //     if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
        //         flowerbed[i] = 1;
        //         n--;
        //         if (n == 0) {
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
        
    }
};