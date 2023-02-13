/*
Q_ID:- 2477.
Q_Name:- Minimum fuel cost to Report to the Capital.
Leetcode
Difficulty:- Medium
Description:- 
    There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.

Constraints:- 
    1 <= n <= 10^5
    roads.length == n - 1
    roads[i].length == 2
    0 <= ai, bi < n
    ai != bi
    roads represents a valid tree.
    1 <= seats <= 10^5
*/
class Solution {
    long long dfs(unordered_map<int, vector<int>> &adj, int curr, vector<bool> &visited, int seats, long long &ans) {
        visited[curr] = true;
        long long node_count = 1;
        for(int v : adj[curr]) {
            if(!visited[v]) {
                node_count += dfs(adj, v, visited, seats, ans);
            }
        }
        if(curr != 0) {
            int x = (node_count % seats == 0) ? 0 : 1;
            ans += node_count/seats + x;
        }
        return node_count;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        //make graph using unordered_map
        int n = roads.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++) {
            int u = roads[i][0];
            int v = roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n+1, false);
        
        long long ans = 0;
        int total_node_cnt = dfs(adj, 0, visited, seats, ans);
        return ans;


    }
};