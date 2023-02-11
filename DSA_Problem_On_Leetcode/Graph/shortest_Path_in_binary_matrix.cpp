/*
Q_ID:- 1091
Q_Name:- Shortest Path in Binary Matrix
Platform:- Leetcode
*/
class Solution {
    
    bool is_valid(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &visited) {
        int n = grid.size();
        if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1 || visited[x][y] == 1) return false;
        return true;
    }

    int bfs_shortest_path(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &visited) {
        visited[x][y] = 1;
        int n = grid.size();
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        queue<pair<int, pair<int,int>>> q;

        q.push({1, {x, y}});

        while(!q.empty()) {
            int curr_x = q.front().second.first;
            int curr_y = q.front().second.second;
            int curr_cnt = q.front().first;
            q.pop();

            if(curr_x == n-1 && curr_y == n-1) return curr_cnt;
            

            for(int i = 0; i < 8; i++) {
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];

                if(is_valid(new_x, new_y, grid, visited)) {
                    visited[new_x][new_y] = 1;
                    q.push({curr_cnt+1, {new_x, new_y}});
                }
            }
        }
        return -1;


    }
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //base case
        if(grid[0][0] == 1) return -1;

        int n = grid.size();
        if(n <= 1) return n;

        vector<vector<int>> visited(n, vector<int>(n, 0));

        return bfs_shortest_path(0, 0, grid, visited);

    }
};