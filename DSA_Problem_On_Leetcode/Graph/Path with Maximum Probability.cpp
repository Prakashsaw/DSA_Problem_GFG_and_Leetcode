
/*
1514. Path with Maximum Probability
Medium
Companies:- Google-5times
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.
*/
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) {
        //use dijsktra algorithm
        //steps-1 make adj list
        unordered_map<int, vector<pair<int, double>>> adj;

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            double prob = succProb[i];
            
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        //step 2
        //max priority queue
        priority_queue<pair<double, int>> pq; //prob, node

        vector<double> ans(n, 0.0);

        pq.push({1.0, s});

        ans[s] = 1;

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            double prob = top.first;
            int node = top.second;

            for(auto &v : adj[node]) {
                int curr_node = v.first;
                double curr_prob = v.second;

                if(curr_prob * prob > ans[curr_node]) {
                    ans[curr_node] = curr_prob * prob;
                    pq.push({curr_prob * prob, curr_node});
                }
            }
        }

        return ans[e];

        //TC = O(E*V (log v))
        //SC = O(E*V)

    }
};