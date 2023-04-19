/*
Q_Name:- Maximum path sum in matrix
Platform:- gfg
Difficulty:- Medium
Company:- Flipkart, Amazon, Microsoft, OYO Rooms, Samsung, MakeMyTrip

Q_Description:- 
    Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

NOTE: We can start from any column in zeroth row and can end at any column in (N-1)th row.

Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1 ≤ N ≤ 500
1 ≤ Matrix[i][j] ≤ 1000
*/

class Solution{
public:

    bool isSafe(int x, int y, int n) {
        if(x >= n || x < 0 || y >= n || y < 0) return false;
        
        return true;
    }

    int solve(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>> &dp) {
        //Base Case
        if(i == n-1) {
            return matrix[i][j];
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        
        int x = 0, y = 0, z = 0;
        
        if(isSafe(i+1, j, n)) {
            x = solve(matrix, n, i+1, j, dp);
        }
        
        if(isSafe(i+1, j-1, n)) {
            y = solve(matrix, n, i+1, j-1, dp);
        } 
        
        if(isSafe(i+1, j+1, n)) {
            z = solve(matrix, n, i+1, j+1, dp);
        }
        
        return dp[i][j] = matrix[i][j] + max({x, y, z});
        
        
    }
    
    
    
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        //recursion plus memoization
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int i = 0; i < n; i++) {
            dp[0][i] = solve(matrix, n, 0, i, dp);
        }
        
        int ans = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            ans = max(ans, dp[0][i]);
        }
        
        return ans;
        
        
        
        
        // //Tabulation method
        
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // for(int i = 0; i < n; i++) {
        //     dp[n-1][i] = matrix[n-1][i];
        // }
        
        // for(int i = n-2; i >= 0; i--) {
        //     for(int j = 0; j < n; j++) {
        //         int a , b, c;
        //         if(isSafe(i+1, j-1, n)) {
        //             a = dp[i+1][j-1];
        //         } else {
        //             a = 0;
        //         }
                
        //         if(isSafe(i+1, j, n)) {
        //             b = dp[i+1][j];
        //         } else {
        //             b = 0;
        //         }
                
        //         if(isSafe(i+1, j+1, n)) {
        //             c = dp[i+1][j+1];
        //         } else {
        //             c = 0;
        //         }
                
        //         dp[i][j] = matrix[i][j] + max({a, b, c});
        //     }
        // }
        
        // int ans = INT_MIN;
        
        // for(int i = 0; i < n; i++) {
        //     ans = max(ans, dp[0][i]);
        // }
        
        // return ans;
        
        //TC  = O(N*N)
        //SC = O(N*N)
    }
};