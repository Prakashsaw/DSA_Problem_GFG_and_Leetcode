/*
Q_Name:- Binary matrix having maximum number of 1s.
Platform:- GFG
Difficulty:- Easy due to constraints
Q_Description:- 
    Given a binary matrix (containing only 0 and 1) of order NxN. All rows are sorted already, We need to find the row number with the maximum number of 1s. Also, find the number of 1s in that row.
Note:

1. In case of a tie, print the smaller row number.
2. Row number should start from 0th index.

Example 1

Input:
N=3
mat[3][3] = {0, 0, 1, 
              0, 1, 1, 
              0, 0, 0}
Output:
Row number = 1
MaxCount = 2
Explanation:
Here, max number of 1s is in row number 1
and its count is 2.
Example 2

Input:
N=3
mat[3][3] = {1, 1, 1, 
              1, 1, 1, 
              0, 0, 0}
Output:
Row number = 0
MaxCount = 3
Your Task:
You don't need to read input or print anything. The task is to complete the function findMaxRow() which takes mat[][] as the 2D matrix and N as the size of matrix. Your task is to find the row number with the maximum number of 1s and find the number of 1s in that row and return the answer in a vector of size 2 where at 0th index will be the row number and at 1th index will be MaxCount.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^3
0 <= mat[][]<= 1
*/
class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int n) {
        //brute force
        //traverse in fiven matrix, count 1's in each row and maximize row number with max 1's
        //TC = O(N*N)
        //SC = O(1)
        // int max_ones_in_a_particular_row = INT_MIN;
        // int row_number = -1;
        // for(int i = 0; i < n; i++) {
        //     int ones_in_each_row = 0;
        //     for(int j = 0; j < n; j++) {
        //         if(mat[i][j] == 1) {
        //             ones_in_each_row++;
        //         }
        //     }
        //     if(ones_in_each_row > max_ones_in_a_particular_row) {
        //         max_ones_in_a_particular_row = ones_in_each_row;
        //         row_number = i;
        //     }
        // }
        // return {row_number, max_ones_in_a_particular_row};
        
        
        
        //Second approach
        //using binary search method
        //since each row are sorted in scending order 
        //so apply binary searach every row to search first and last index of 1
        //TC = O(NlogN)
        //SC = O(1).
        
        // int max_ones_in_a_particular_row = INT_MIN;
        // int row_number = -1;
        // for(int i = 0; i < n; i++) {
        //     int ones_in_each_row = 0;
        //     // for(int j = 0; j < n; j++) {
        //     //     if(mat[i][j] == 1) {
        //     //         ones_in_each_row++;
        //     //     }
        //     // }
        //     //instead of this apply binary search methods lower_bound and upper_bound
        //     if(mat[i][n-1] == 0) {
        //         ones_in_each_row = 0;
        //     } else if(mat[i][0] == 1) {
        //         ones_in_each_row = n;
        //     } else {
        //         int l = lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin();
        //         int r = upper_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin();
        //         r--;
        //         ones_in_each_row = r-l+1;
        //     }
        //     if(ones_in_each_row > max_ones_in_a_particular_row) {
        //         max_ones_in_a_particular_row = ones_in_each_row;
        //         row_number = i;
        //     }
        // }
        // return {row_number, max_ones_in_a_particular_row};
        
        
        
        //Third appraoch
        //Most optimized appraoch
        //TC = O(N+N) = O(2N) = O(N)
        //SC = O(1)
        int ans_row = 0;
        int no_of_ones_max = 0;
        int row = 0;
        int col = n-1;
        
        while(row < n && col >= 0) {
            if(mat[row][col] == 1) {
                ans_row = row;
                no_of_ones_max = n-col;
                col--;
            } else {
                row++;
            }
        }
        return {ans_row, no_of_ones_max};
        
    }
};