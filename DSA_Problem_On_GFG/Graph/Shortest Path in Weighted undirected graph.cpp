/*
Q_Name:- Shortest Path in Weighted undirected graph
Platform:- gfg
Difficulty:- medium
Topic:- Graph, Dijkstra's Algorithm
Description:- 
    You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.

Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5

Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestPath() which takes n vertex and m edges and vector of edges having weight as inputs and returns the shortest path between vertex 1 to n.

Expected Time Complexity: O(m* log(n))
Expected Space Complexity: O(n)

Constraint:
2 <= n <= 10^5
0 <= m <= 10^5
0<= a, b <= n
1 <= w <= 10^5

*/

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //source path is always 1 i.e s = 1;
        
        //use dijkstra's algorithm
        
        
        //first build grapg using unorered_map
        
        
        unordered_map<int, vector<pair<int, int>> > adj;
        
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        //then write dijkastra algorithm
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        vector<int> result(n+1, INT_MAX);
        
        pq.push({0, 1}); //(dis, source_node)
        
        vector<int> parent(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        result[1] = 0;
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int node = top.second;
            int d = top.first;
            
            for(auto &v : adj[node]) {
                int curr_node = v.first;
                int curr_d = v.second;
                
                if(curr_d + d < result[curr_node]) {
                    result[curr_node] = curr_d + d;
                    pq.push({curr_d + d, curr_node});
                    
                    parent[curr_node] = node;
                }
            }
        }
        
        vector<int> ans_path;
        int node = n;
        while(parent[node] != node) {
            ans_path.push_back(node);
            node = parent[node];
        }
        
        if(ans_path.size() == 0) {
            ans_path.push_back(-1);
            return ans_path;
        }
        ans_path.push_back(1);
        
        reverse(ans_path.begin(), ans_path.end());
        
        return ans_path;
    }
};