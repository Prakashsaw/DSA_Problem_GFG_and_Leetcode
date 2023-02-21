/*
Q_Name:- Fill the Matrix.
GFG
escription:- Given a matrix with dimensions N x M, entirely filled with zeroes except for one position at co-ordinates X and Y containing '1'. Find the minimum number of iterations in which the whole matrix can be filled with ones.
Note: In one iteration, '1' can be filled in the 4 neighbouring elements of a cell containing '1'.

Example 1:

Input:
N = 2, M = 3
X = 2, Y = 3
Output: 3 

Explanation: 3 is the minimum possible 
number of iterations in which the
matrix can be filled.
Example 2:

Input:
N = 1, M = 1
X = 1, Y = 1 
Output: 0

Explanation: The whole matrix is 
already filled with ones.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minIterations() which takes the dimensions of the matrix N and M and the co-ordinates of the initial position of '1' ie X and Y as input parameters and returns the minimum number of iterations required to fill the matrix.


Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N, M ≤ 103
1 ≤ X ≤ N
1 ≤ Y ≤ M 

*/
class Solution{ 
    int ans = 0;
    
    bool is_valid(int n, int m, int x, int y, vector<vector<int>> &visited) {
        
        if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] == 1) return false;
        
        return true;
    }
    
    void bfs(int n, int m, int x,  int y, vector<vector<int>> &visited) {
        
        visited[x][y] = 1;
        
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        queue<pair<int, pair<int,int>>> q;

        q.push({0, {x, y}});

        while(!q.empty()) {
            int curr_x = q.front().second.first;
            int curr_y = q.front().second.second;
            int curr_cnt = q.front().first;
            q.pop();

            ans = max(ans, curr_cnt);
            

            for(int i = 0; i < 4; i++) {
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];

                if(is_valid(n, m, new_x, new_y, visited)) {
                    visited[new_x][new_y] = 1;
                    q.push({curr_cnt+1, {new_x, new_y}});
                }
            }
        }
    }
public:
    int minIteration(int n, int m, int x, int y){
        // vector<vector<int>> visited(n, vector<int>(m, 0));
        // bfs(n, m, x-1, y-1, visited);
        // return ans;
        // //TC = O(N*M)
        // //SC = O(N*M)
        
        //Onother appraoch
        int row_max = max(x-1, n-x);
        int col_max = max(y-1, m-y);
        
        return row_max + col_max;
        //TC = O(1)
        //SC = O(1)
    }
};