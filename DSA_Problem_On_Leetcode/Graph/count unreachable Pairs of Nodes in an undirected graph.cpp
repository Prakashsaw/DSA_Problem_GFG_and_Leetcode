
/*
Q_ID:- 2316.
Q_Name:- count unreachable Pairs of Nodes in an undirected graph
Platform:- Leetcode.
Difficulty:- Medium
Q_description:- 
    You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

 

Example 1:


Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
Example 2:


Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
 

Constraints:

1 <= n <= 10^5
0 <= edges.length <= 2 * 10^5
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated edges.
*/


class Solution {
    long long int findProductPairSum(vector<long long int> &A) {
        int n = A.size();
        // calculating array sum (a1 + a2  ... + an)
        long long int array_sum = 0;
        for (int i = 0; i < n; i++)
            array_sum = array_sum + A[i];
    
        // calculating square of array sum
        // (a1 + a2 + ... + an)^2
        long long int array_sum_square = array_sum * array_sum;
    
        // calculating a1^2 + a2^2 + ... + an^2
        long long int individual_square_sum = 0;
        for (int i = 0; i < n; i++)
            individual_square_sum += A[i]*A[i];
    
        // required sum is (array_sum_square -
        // individual_square_sum) / 2
        return (array_sum_square - individual_square_sum)/2;
    }

    void dfs(int curr, vector<int> &vis, unordered_map<int, vector<int>> &adj, long long int &cnt) {
        vis[curr] = 1;
        cnt++;
        for(auto v : adj[curr]) {
            if(!vis[v]) {
                dfs(v, vis, adj, cnt);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        //first find connected components with total edge count
        //store int into vector 
        //now apply approach to find pair product sum in an array in time O(N)
        // now return ans.
        //TC = O(N)
        //SC = O(N)

        //first build graph
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<long long int> v;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                long long int cnt = 0;
                dfs(i, vis, adj, cnt);
                v.push_back(cnt);
            }
        }

        return findProductPairSum(v);
    }
};