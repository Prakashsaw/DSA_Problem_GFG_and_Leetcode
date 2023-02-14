/*
Q_Id:- 67.
Q_Name:- Add Binary.
Platform:- Leetcode
Difficulty:- Easy

Description:- 
    Given two binary strings a and b, return their sum as a binary string.
Constraints:- 
    1 <= a.length, b.length <= 10^4
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.

*/
class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();

        int i = n1-1;
        int j = n2-1;
        string ans = "";
        int carry = 0;
        
        while(i >= 0 || j >= 0) {
            int sum = 0;
            if(i >= 0) {
                sum += (a[i]-'0');
            }
            if(j >= 0) {
                sum += (b[j]-'0');
            }
            sum += carry;
            if(sum >= 2) {
                carry = 1;
                sum = sum%2;
            } else {
                carry = 0;
            }
            ans += (sum + '0');

            i--;
            j--;
        }
        if(carry) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};