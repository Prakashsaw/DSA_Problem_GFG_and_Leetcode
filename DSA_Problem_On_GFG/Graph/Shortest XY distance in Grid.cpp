/*
Q_NAME:- Shortest XY distance in Grid
//Same Question as leetcode:- 1091. Shortest Path in Binary Matrix
Q_Description:- 
    Give a N*M grid of characters 'O', 'X', and 'Y'. Find the minimum Manhattan distance between a X and a Y.

Manhattan Distance :
| row_index_x - row_index_y | + | column_index_x - column_index_y |


Example 1:

Input:
N = 4, M = 4
grid  = {{X, O, O, O}
         {O, Y, O, Y}
         {X, X, O, O}
         {O, Y, O, O}}
Output:
1
Explanation:
{{X, O, O, O}
{O, Y, O, Y}
{X, X, O, O}
{O, Y, O, O}}
The shortest X-Y distance in the grid is 1.
One possible such X and Y are marked in bold
in the above grid.
Example 2:

Input:
N = 3, M = 3
grid = {{X, X, O}
        {O, O, Y}
        {Y, O, O}}
Output :
2
Explanation:
{{X, X, O}
 {O, O, Y}
 {Y, O, O}}
The shortest X-Y distance in the grid is 2.
One possible such X and Y are marked in bold
in the above grid.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function shortestXYDist() which takes two integers N, and M and an 2D list of size N*M as input and returns the shortest Manhattan Distance between a X and a Y.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)


Constraints:
1 ≤ N*M ≤ 10^5 

There exists at least one 'X' and at least one 'Y' in the grid.
*/
class Solution {
    bool isSafe(int x, int y, int n, int m, vector<vector<int>> &vis) {
        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0) {
            return true;
        }
        return false;
    }
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        //shortest Manhattan distance between X and Y
        //apply multi source BFS for calculating shortest distance between multiple 
        //source to multi destination
        //TC = O(N*M)
        //SC = O(N*M)
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int ans = 0;
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int x = front.second.first;
            int y = front.second.second;
            int curr_dis = front.first;
            
            if(grid[x][y] == 'Y') {
                return curr_dis;
            }
            
            for(int i = 0; i < 4; i++) {
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                
                if(isSafe(new_x, new_y, n, m, vis)) {
                    q.push({curr_dis+1, {new_x, new_y}});
                    vis[new_x][new_y] = 1;
                }
            }
        }
        return -1;
    }
};