/*
Q_Name:- Geeks Island
Platform:-GFG
Difficulty:- Medium

Q_Description:- 
    Geeks Island is represented by an N * M matrix mat. 
    The island is touched by the Indian Ocean from the 
    top and left edges and the Arabian Sea from the right 
    and bottom edges. Each element of the matrix represents 
    the height of the cell.

Due to the rainy season, the island receives a lot of rainfall, 
and the water can flow in four directions(up, down, left, or right) 
from one cell to another one with height equal or lower.

You need to find the number of cells from where water can flow to 
both the Indian Ocean and the Arabian Sea.

Constraints:- 
    1 <= N, M <= 10^3
    1 <= mat[i][j] <= 10^6
*/
class Solution{  
    bool is_valid(vector<vector<int>> &mat, int x, int y, vector<vector<bool>> &vis) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == true) return false;
        
        return true;
    }
    void dfs(vector<vector<int>> &mat, int x, int y, vector<vector<bool>> &vis, int prev_greater) {
        if(prev_greater > mat[x][y]) return;
        
        prev_greater = mat[x][y];
        
        vis[x][y] = true;
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++) {
            if(is_valid(mat, dx[i]+x, dy[i]+y, vis)) {
                dfs(mat, dx[i]+x, dy[i]+y, vis, prev_greater);
            }
        }
    }
public:
    int water_flow(vector<vector<int>> &mat,int n,int m){
    // Write your code here.
        vector<vector<bool>> vis_for_Inidan(n, vector<bool>(m, false));
        vector<vector<bool>> vis_for_Arabian(n, vector<bool>(m, false));
        
        for(int i = 0; i < m; i++) {
            dfs(mat, 0, i, vis_for_Inidan, INT_MIN);
        }
        for(int i = 0; i < n; i++) {
            dfs(mat, i, 0, vis_for_Inidan, INT_MIN);
        }
        
        for(int i = m-1; i >= 0; i--) {
            dfs(mat, n-1, i, vis_for_Arabian, INT_MIN);
        }
        for(int i = n-1; i >= 0; i--) {
            dfs(mat, i, m-1, vis_for_Arabian, INT_MIN);
        }
        
        //now count cell with visited on both visited matrix
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis_for_Inidan[i][j] && vis_for_Arabian[i][j]) {
                    ans++;
                }
            }
        }
        
        return ans;
        //TC = O(N^3) Still sccepted
        //SC = O(N^2)
    }
};
