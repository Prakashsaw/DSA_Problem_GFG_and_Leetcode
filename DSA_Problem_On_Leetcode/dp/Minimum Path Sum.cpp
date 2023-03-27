
/*
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/
class Solution {
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        //base case
        if(i == n-1 && j == m-1) {
            return grid[i][j];
        }
        if(i >= n || j >= m) {
            return INT_MAX;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j+1, n, m, grid, dp);
        int down = solve(i+1, j, n, m, grid, dp);

        return dp[i][j] = (min(right, down) + grid[i][j]);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        //basic recursion + memoization appraoch
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, grid[0][0]));
        //return solve(0, 0, n, m, grid, dp);

        //Tabulation
        //fill first col
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        //fill first row
        for(int i = 1; i < m; i++) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                
                int up_as_right = dp[i][j-1];
                int left_as_down = dp[i-1][j];
                dp[i][j] = (min(up_as_right, left_as_down) + grid[i][j]);
            }
        }
        return dp[n-1][m-1];

    }
};