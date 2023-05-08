/*
Q_Id?:- 1572.
Q_Name:-  Matrix Diagonal Sum.
Platform: Leetcode
Difficulty:- Easy
Q_Description:- 
    Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

Example 1:


Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:

Input: mat = [[5]]
Output: 5
 

Constraints:

n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100

*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < n) {
            sum += mat[i][j];
            i++;
            j++;
        }
        i = 0;
        j = n-1;
        while(i < n && j >= 0) {
            sum += mat[i][j];
            i++;
            j--;
        }
        if(n % 2 == 1) {
            sum -= mat[n/2][n/2];
        }
        return sum;
        //TC = O(N)
        //SC = O(1)
        
    }
};