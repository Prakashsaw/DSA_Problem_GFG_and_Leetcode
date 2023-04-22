/*
Q_Name:- Shortest path in Undirected Graph having unit distance
Q_Description:- 
    You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Example:

Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4 ,5]
,[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
Your Task:

You don't need to print or input anything. Complete the function shortest path() which takes a 2d vector or array edges representing the edges of undirected graph with unit weight, an integer N as number nodes, an integer M as number of edges and an integer src as the input parameters and returns an integer array or vector, denoting the vector of distance from src to all nodes.

Constraint:
1<=n,m<=100
1<=adj[i][j]<=100

Expected Time Complexity: O(N + E), where N is the number of nodes and E is edges
Expected Space Complexity: O(N)
*/
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        
        
        unordered_map<int, vector<pair<int, int>> > adj;
        
        for(int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = 1;
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        //then write dijkastra algorithm
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        vector<int> result(n, INT_MAX);
        
        pq.push({0, src}); //(dis, source_node)
        
        result[src] = 0;
        
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
                    
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(result[i] == INT_MAX) {
                result[i] = -1;
            }
        }
        
        return result;
        
    }
};