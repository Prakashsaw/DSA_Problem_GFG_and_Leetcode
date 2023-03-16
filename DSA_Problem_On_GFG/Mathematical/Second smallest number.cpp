/*
Q_Name:- Second smallest number;
Platform:- GFG
Difficulty:- Medium
Q_Description:- 
    The task is to find the second smallest number with a given sum of digits as S and the number of digits as D.
Example 1:

Input:
S = 9 
D = 2
Output:
27
Explanation:
18 is the smallest number possible with sum = 9
and total digits = 2, Whereas the second
smallest is 27.
Example 2:

Input:
S = 16
D = 3
Output:
178
Explanation:
169 is the smallest number possible with sum is
16 and total digits = 3, Whereas the second
smallest is 178.

Your Task:
You don't need to read input or print anything. Your task is to complete the function secondSmallest() which takes the two integers S and D respectively and returns a string which is the second smallest number if possible, else return "-1".

Expected Time Complexity: O(D)
Expected Space Complexity: O(1)

Constraints:
1 ≤ S ≤ 10^5
1 ≤ D ≤ 10^5
*/
class Solution{   
  public:
    string secondSmallest(int s, int d){
        
        /*
        steps:- 
        1)first find smallest num with given constraints
        2) then find second smallest element after modifying this nus array

        */
        int num[d];
        for(int i = d-1; i >= 1; i--) {
            int d = min(s-1, 9);
            num[i] = d;
            s = s-d;
            if(s < 0) return "-1";
        }
        if(s > 9) return "-1";
        num[0] = s;
        
        //now making second smallest numbser => converting it into string and then return that ans
        //if not be possible of making second smallest number then after comming out from loop 
        //return -1
        for(int i = d-1; i >= 1; i--) {
            if(num[i] != 0 && num[i-1] != 9) {
                num[i] -= 1;
                num[i-1] += 1;
                string ans = "";
                for(int i = 0; i < d; i++) {
                    ans += num[i] + '0';
                }
                return ans;
            }
        }
        return "-1";
        
        
        
        
    }
};