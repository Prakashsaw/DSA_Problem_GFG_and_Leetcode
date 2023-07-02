/*
Que:- Copy Set Bits in Range
Level:- Easy
Companies:- 
    D-E-Shaw, Ddobe
Description: -
    Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 31. You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.

Note: Range count will be from Right to Left & start from 1.

Example 1:

Input: 
X = 44, Y = 3 
L = 1,  R = 5
Output: 
47
Explaination: 
Binary represenation of 44 and 3 is 101100 and 000011. So in the range 1 to 5 there are two set bits of 3 (1st & 2nd position). If those are set in 44 it will become 101111 which is 47.
Example 2:

Input: 
X = 16, Y = 2
L = 1,  R = 3
Output: 18
Explaination: Binary represenation of 16 and 2 is 10000 and 10. If the mentioned conditions are applied then 16 will become 10010 which is 18.
Your Task:
You do not need to read input or print anything. Your task is to complete the function setSetBit() which takes the numbers X, Y, L and R as input parameters and returns the modified value of X.

Expected Time Complexity: O(R - L)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ X, Y ≤ 109
1 ≤ L ≤ R ≤ 32


*/

class Solution{
    public:
    void print(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    int setSetBit(int x, int y, int l, int r){
        // code here
        vector<int> x_bits(32, 0);
        vector<int> y_bits(32, 0);
        int i = 0;
        while(x > 0) {
            if(x&1) {
                x_bits[i] = 1;
            }
            i++;
            x >>= 1;
        }
        i = 0;
        while(y > 0) {
            if(y&1) {
                y_bits[i] = 1;
            }
            i++;
            y >>= 1;
        }
        
        // print(x_bits);
        // print(y_bits);
        
        
        for(int i = l-1; i < r; i++) {
            if(y_bits[i] & 1) {
                x_bits[i] = y_bits[i];
            }
        }
        
        // print(x_bits);
        
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            ans += pow(2, i) * x_bits[i];
        }
        
        return ans;
        
        //TC = O(log(x) + log(y) + R-L) = O(log(max(x, y))
        //SC = O(32) = O(1)
        
        
    }
};