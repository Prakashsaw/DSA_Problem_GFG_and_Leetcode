/*
Q_Id:- 2360. 
Q_Name:- Longest Cycle in a Graph
Platform:- Leetcode
Difficulty:- Hard
Description:- 
    You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

 

Example 1:


Input: edges = [3,3,4,2,3]
Output: 3
Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
The length of this cycle is 3, so 3 is returned.
Example 2:


Input: edges = [2,-1,3,1]
Output: -1
Explanation: There are no cycles in this graph.
 

Constraints:

n == edges.length
2 <= n <= 10^5
-1 <= edges[i] < n
edges[i] != i
*/
class Solution {
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int curr, vector<bool> &vis, vector<bool> &inRecursion) {
        vis[curr] = true;
        inRecursion[curr] = true;
        
        for(auto &v : adj[curr]) {
            if(vis[v] == false) {
                if(isCycleDFS(adj, v, vis, inRecursion)) return true;
            }
            else if(inRecursion[v] == true) return true;
            //Above both are same
            
        }
        inRecursion[curr] = false; //backtrack
        return false;
    }
public:
    int longestCycle(vector<int>& edges) {
        //appraoch
        //reverse the edges position of graph
        //now detect cycle in directed graph
        //now if cycle detect return any one node of that cycle
        //by using that node find total node in that cycle
        //maximize ans with total node in that cycle
        //retrun ans

        //build graph/adj matrix in reverse edges
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < edges.size(); i++) {
            int v = i;
            int u = edges[i];
            if(u != -1) {
                adj[u].push_back(v);
            }
        }
        int n = edges.size();

        vector<bool> vis(n, false);

        int ans = -1;
        vector<bool> inRecursion(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                bool getAns = isCycleDFS(adj, i, vis, inRecursion);
                if(getAns) {
                    int st_vertex = i;
                    int cnt = 1;
                    while(edges[st_vertex] != i) {
                        cnt++;
                        st_vertex = edges[st_vertex];
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;

    }
};