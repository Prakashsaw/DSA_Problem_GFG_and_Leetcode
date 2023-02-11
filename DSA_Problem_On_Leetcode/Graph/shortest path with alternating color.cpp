/*
Q_ID:- 1129. 
Q_Name:- Shortest Path with Alternating Colors.
Platform:- Leetcode
Constraints:-
    1 <= n <= 100
    0 <= redEdges.length, blueEdges.length <= 400
    redEdges[i].length == blueEdges[j].length == 2
    0 <= ai, bi, uj, vj < n
*/
class Solution {
    vector<int> ans;

    void bfs(unordered_map<int, vector<pair<int, int>>> &adj, int curr, vector<vector<bool>> &visited) {
        ans[curr] = 0;
        queue<vector<int>> q; //for storing three things in queue {node, steps_till_now, color}

        q.push({curr, 0, -1});

        visited[curr][0] = true;

        while(!q.empty()) {

            vector<int> front = q.front();
            q.pop();

            int parent_node = front[0];
            int prev_steps = front[1];
            int prev_color = front[2];

            for(auto v : adj[parent_node]) {

                int curr_node = v.first;
                int curr_color = v.second;

                if(!visited[curr_node][curr_color] && prev_color != curr_color) {
                    
                    visited[curr_node][curr_color] = true;

                    if(ans[curr_node] == -1) {
                        ans[curr_node] = prev_steps+1;
                    }

                    q.push({curr_node, prev_steps+1, curr_color});

                }
            }
        }
     }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //first steps to make adj list
        unordered_map<int, vector<pair<int, int>>> adj;
        int red_color_size = redEdges.size();
        int blue_color_size = blueEdges.size();
        //red use code = 0
        //blue use code = 1
        for(int i = 0; i < red_color_size; i++) {
            int u = redEdges[i][0];
            int v = redEdges[i][1];

            adj[u].push_back({v, 0});
        }

        for(int i = 0; i < blue_color_size; i++) {
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];

            adj[u].push_back({v, 1});
        }

        //second steps make visited array 
        //curr_node versus curr color of visite or we can say that child versus child_color

        vector<vector<bool>> visited(n, vector<bool>(2, false));
        ans = vector<int> (n, -1);

        bfs(adj, 0, visited);

        return ans;
        //TC = O(N*N)
        //SC = O(N+E)

    }
};