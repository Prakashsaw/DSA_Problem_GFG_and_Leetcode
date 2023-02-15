/*
Q_ID:- 989.
Q_Name:- Add To Array form of integer.
Pltform:- Leetcode
Difficulty:- Easy 

Description:- 
    The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

Constraints:- 
    1 <= num.length <= 104
    0 <= num[i] <= 9
    num does not contain any leading zeros except for the zero itself.
    1 <= k <= 10^4
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = 0;
        int i = num.size()-1;
        while(k > 0 || i >= 0) {
            int digit = k%10;
            k /= 10;
            int x = (i >= 0) ? num[i] : 0;
            int sum = x + digit + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
        }
        while(carry || i >= 0) {
            int x = (i >= 0) ? num[i] : 0;
            int sum = x + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
        }
        
        reverse(ans.begin(), ans.end());

        return ans;

    }
};