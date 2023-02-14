/*
Q_name:- Walls coloring
Difficulty:- Medium
Descrtiption:- 
    There is a row of N walls in Geeksland. The king of Geeksland ordered 
    Alexa to color all the walls on the occasion of New Year. Alexa can color 
    each wall with either pink, black, or yellow. The cost associated with 
    coloring each wall with a particular color is represented by a 2D array 
    colors of size N*3 , where colors[i][0], colors[i][1], and colors[i][2] 
    is the cost of painting ith wall with colors pink, black, and yellow respectively.

    You need to find the minimum cost to color all the walls such that no two adjacent 
    walls have the same color.
    
Constraints:- 
    1 <= N <= 10^5
    1 <= colors[i][0], colors[i][1], colors[i][2] <= 10^4

Platform:- GFG
*/

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        //Simple appraoch include not include
        /*
        //Brute force
        //dp approach
        //TC = O(N)
        //SC = O(N)
        
        if(n == 1) return min({colors[0][0], colors[0][1], colors[0][2]});
        
        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        dp[0][0] = colors[0][0];
        dp[0][1] = colors[0][1];
        dp[0][2] = colors[0][2];
        
        for(int i = 1; i < n; i++) {
            dp[i][0] = colors[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = colors[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = colors[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        
        return min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
        */
        
        
        //sapce optimize
        //TC = O(N)
        //SC = O(1)
        if(n == 1) return min({colors[0][0], colors[0][1], colors[0][2]});
        
        int pink_cost = colors[0][0];
        int black_cost = colors[0][1];
        int yellow_cost = colors[0][2];
        
        for(int i = 1; i < n; i++) {
            int new_pink_cost = colors[i][0] + min(black_cost, yellow_cost);
            int new_black_cost = colors[i][1] + min(pink_cost, yellow_cost);
            int new_yellow_cost = colors[i][2] + min(pink_cost, black_cost);
            
            pink_cost = new_pink_cost;
            black_cost = new_black_cost;
            yellow_cost = new_yellow_cost;
        }
        
        return min({pink_cost, black_cost, yellow_cost});
    }
};
