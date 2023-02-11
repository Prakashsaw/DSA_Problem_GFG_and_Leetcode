//Q_id:- 1162. 
//Q_Name:- As Far from Land as Possible
//Topics- Graph on 2-D grid

class Solution {
    bool is_valid(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size();
        if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1) return false;
        return true;
    }
    
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int ans = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        //base case
        if(q.size() == 0 || q.size() == n * n) return -1;
        
        int level = -1;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()) {
            level++;

            int sz = q.size();
            
            for(int i = 0; i < sz; i++) {
                int curr_x = q.front().first;
                int curr_y = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int new_x = curr_x + dx[i];
                    int new_y = curr_y + dy[i];

                    if(is_valid(new_x, new_y, grid)) {
                        grid[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        return level;
    }
};
