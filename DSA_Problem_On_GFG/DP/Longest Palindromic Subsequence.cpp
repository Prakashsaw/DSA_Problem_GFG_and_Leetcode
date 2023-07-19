/*
Longest Palindromic Subsequence
Medium
Companies:- Amazon, Google

Given a String, find the longest palindromic subsequence.

Example 1:

Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.
Example 2:

Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer denoting the length of the longest palindromic subsequence of S.

Expected Time Complexity: O(|S|*|S|).
Expected Auxiliary Space: O(|S|*|S|).

Constraints:
1 ≤ |S| ≤ 1000
*/
class Solution{
  public:
    
    vector<vector<int>> dp;
    int solve(string A, string B, int i, int j) {
        if(i >= A.length() || j >= B.length()) {
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        
        if(A[i] == B[j]) {
            ans = 1 + solve(A, B, i+1, j+1);
        } else {
            int a = solve(A, B, i, j+1);
            int b = solve(A, B, i+1, j);
            int c = solve(A, B, i+1, j+1);
            ans = max({a, b, c});
        }
        return dp[i][j] = ans;
    }
    int solveTabulation(string A, string B, int n, int m) {
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(A[n-i] == B[m-j]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    int a = dp[i][j-1];
                    int b = dp[i-1][j];
                    int c = dp[i-1][j-1];
                    
                    dp[i][j] = max({a, b, c});
                }
            }
        }
        return dp[n][m];
    }
    int LCS(string A, string B) {
        //Recursive approach
        //ststus:- TLE
        //Now memoize it
        int n = A.length();
        int m = B.length();
        dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        // return solve(A, B, 0, 0);
        return solveTabulation(A, B, n, m);
    }
    
    int longestPalinSubseq(string A) {
        //code here
        //Reverse this string as B
        //then apply LCS(Longest common subsequences)
        string B = A;
        reverse(A.begin(), A.end());
        
        return LCS(A, B);
    }
};