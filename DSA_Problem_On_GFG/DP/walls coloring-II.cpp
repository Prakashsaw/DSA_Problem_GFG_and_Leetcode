/*
Q_Name:- Walls coloring-II
Reneralization for number of color k.
Platform:- GFG.
Q_Description:- 
    There is a row of N walls in Geeksland. The king of Geeksland ordered Alexa to color all the walls on the occasion of New Year. Alexa can color each wall with one of the K colors. The cost associated with coloring each wall with a particular color is represented by a 2D costs array of size N * K. For example, costs[0][0] is the cost of coloring wall 0 with color 0; costs[1][2] is the cost of coloring wall 1 with color 2, and so on... Find the minimum cost to color all the walls such that no two adjacent walls have the same color.

Note: If you are not able to paint all the walls, then you should return -1.

Example 1:

Input:
N = 4, K = 3
costs[][] = {{1, 5, 7},
             {5, 8, 4},
             {3, 2, 9},
             {1, 2, 4}}

Output:
8
Explanation:
Paint wall 0 with color 0. Cost = 1
Paint wall 1 with color 2. Cost = 4
Paint wall 2 with color 1. Cost = 2
Paint wall 3 with color 0. Cost = 1
Total Cost = 1 + 4 + 2 + 1 = 8
Example 2:

Input:
N = 5, K = 1
costs[][] = {{5},
             {4},
             {9},
             {2},
             {1}}
Output:
-1
Explanation:
It is not possible to color all the walls under the given conditions.


Your Task:

Your task is to complete the function minCost() which takes a 2D integer matrix costs as the only argument and returns an integer, representing the minimum cost to paint all the walls. If you are not able to paint all the walls, then you should return -1

Expected Time Complexity: O(N*K)
Expected Space Complexity: O(N*K)

Constraints:

0 <= N <= 10^3
0 <= K <= 10^3
1 <= costs[i][j] <= 10^5
*/
class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        
        int n = costs.size();
        int k = costs[0].size();
        
        if(k == 1) {
            if(n == 1) return costs[0][0];
            else return -1;
        }
        
        vector<vector<int>> dp(k, vector<int>(n, 0));
        int first_min = INT_MAX;
        int second_min = INT_MAX;
        for(int j = 0; j < k; j++) {
            dp[j][0] = costs[0][j];
            int x = dp[j][0];
            if(first_min > x) {
                second_min = first_min;
                first_min = x;
            } else if(second_min > x) {
                second_min = x;
            }
        }
        
        //cout << first_min << " " << second_min << endl;
        
        for(int i = 1; i < n; i++) {
            
            int new_first_min = INT_MAX;
            int new_second_min = INT_MAX;
            
            for(int j = 0; j < k; j++) {
                int mini;
                if(dp[j][i-1] != first_min) {
                    mini = first_min;
                } else {
                    mini = second_min;
                }
                
                dp[j][i] = costs[i][j] + mini;
                
                int x = dp[j][i];
                if(new_first_min > x) {
                    new_second_min = new_first_min;
                    new_first_min = x;
                } else if(new_second_min > x) {
                    new_second_min = x;
                }
            }
            
            first_min = new_first_min;
            second_min = new_second_min;
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < k; i++) {
            ans = min(ans, dp[i][n-1]);
        }
        if(ans == INT_MAX) return -1;
        return ans;
        //TC = O(N*K)
        //SC = O(N*K)
    }
};