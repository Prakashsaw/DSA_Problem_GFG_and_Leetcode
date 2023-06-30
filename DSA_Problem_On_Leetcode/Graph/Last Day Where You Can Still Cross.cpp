/*
Que:- 1970. Last Day Where You Can Still Cross
Level:- Hard
Companies:- Google, Meta
There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 

Example 1:


Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
Output: 2
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 2.
Example 2:


Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
Output: 1
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 1.
Example 3:


Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.
 

Constraints:

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.
*/

class Solution {
public:

    int M, N;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool isSafe(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 1) return false;

        return true;

    }
    // bool DFS(vector<vector<int>>& grid, int i, int j) {
    //     if(i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 1) return false;

    //     if(i == M-1) return true;

    //     grid[i][j] = 1;

        
    //     for(int k = 0; k < 4; k++) {
    //         if(DFS(grid, i+dx[k], j+dy[k])) {
    //             return true;
    //         }
    //     }

    //     return false;

    // }

    bool BFS(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 1) return false;

        if(i == M-1) return true;

        grid[i][j] = 1;
        
        queue<pair<int, int>> q;

        q.push({i, j});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            i = curr.first;
            j = curr.second;

            if(i == M-1) return true;

            for(int k = 0; k < 4; k++) {
                int new_x = i+dx[k];
                int new_y = j+dy[k];

                if(isSafe(grid, new_x, new_y)) {
                    grid[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }
        
        return false;

    }

    bool canCross(vector<vector<int>>& cells, int day) {
        vector<vector<int>> grid(M, vector<int>(N));
        for(int i = 0; i <= day; i++) {
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;

            grid[x][y] = 1;

        }

        for(int col = 0; col < N; col++) {
            if(grid[0][col] == 0 && BFS(grid, 0, col)) return true;
        }
        return false;

    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        //brute force
        //starting from day = 0 to check that for what last day we can go from top to bottom
        int n = cells.size();
        M = row;
        N = col;
        int day = 0;
        // for(int i = 0; i < n; i++) {
        //     if(canCross(cells, i)) {
        //         day = i;
        //     } else break;
        // }
        // return day+1;
        //TC = O(N*M * N*M)
        //SC = O(N*M)
        //Status:- TLE


        //Optimize by using binary search
        int s = 0;
        int e = n-1;
        int mid;
        while(s <= e) {
            mid = s + (e-s)/2;
            if(canCross(cells, mid)) {
                day = mid;
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        return day+1;

        //TC = O(log(M*N)* M*N)
        //SC = O(N*M)
    }
};