class Solution {
    
    bool solve(int n, int k, int target, vector<int> &coins, vector<vector<vector<int>>> &dp) {
        if(k == 0 && target == 0) return 1;
        
        if((k == 0 && target != 0) || (k != 0 && target <= 0)) return 0;
        
        if(n <= 0) return 0;
        
        if(dp[n][k][target] != -1) return dp[n][k][target];
        
        dp[n][k][target] = solve(n, k-1, target-coins[n-1], coins, dp) || solve(n-1, k, target, coins, dp);
        
        return dp[n][k][target];
    }
    
  public:
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        
        
        //brute force recursive approach
        //Status: TLE
        
        //optimize by recursion + memoization take or not take appraoch
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(target+1, -1)));
        return solve(n, k, target, coins, dp);
    }
};