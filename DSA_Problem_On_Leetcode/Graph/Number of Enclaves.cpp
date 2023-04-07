/*
Q_Id:- 1020.
Q_Name:-  Number of Enclaves.
Platform:- Leetcode
Difficulty:- Medium
Description:- 
    You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
*/

/*
Logic:- 
    start either dfs or bfs from all four boundry means first row, first col, last row and last col
    mark visited for all 1's.
    now traverse in grid and if you find grid[i][j] == 1 and also vis[i][j] not be visited then cunt++.
    finally return count;

    //TC = O(N*M)
    //SC = O(N*M)
    
*/

class Solution {
    bool isSafe(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        if(x >= n || x < 0 || y >= m || y < 0 || grid[x][y] == 0 || vis[x][y] == 1) {
            return false;
        }
        return true;
    }

    void bfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[x][y] = 1;
        queue<pair<int, int>> q;
        q.push({x, y});

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            x = front.first;
            y = front.second;

            for(int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if(isSafe(grid, new_x, new_y, vis)) {
                    vis[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //base case
        if(n <= 2 || m <= 2) return 0;

        vector<vector<int>> vis(n, vector<int> (m, 0));

        //first col
        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                bfs(grid, i, 0, vis);
            }
        }

        //first row
        for(int i = 0; i < m; i++) {
            if(!vis[0][i] && grid[0][i] == 1) {
                bfs(grid, 0, i, vis);
            }
        }

        //last col
        for(int i = 0; i < n; i++) {
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                bfs(grid, i, m-1, vis);
            }
        }

        //last row
        for(int i = 0; i < m; i++) {
            if(!vis[n-1][i] && grid[n-1][i] == 1) {
                bfs(grid, n-1, i, vis);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};