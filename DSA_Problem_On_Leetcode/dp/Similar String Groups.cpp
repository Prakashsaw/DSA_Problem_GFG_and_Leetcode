/*
Q_Id:- 839.
Q_Name:-  Similar String Groups
Difficulty:- Hard
Description:- 
    Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

 

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1
 

Constraints:

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.
*/

class Solution {
public:

    // //union and find code/implementation:- Disjoint set
    // vector<int> parent;
    // vector<int> rank;

    // int find(int i) {
    //     if(i == parent[i]) {
    //         return i;
    //     }

    //     return parent[i] = find(parent[i]);
    // }

    // void union_find(int x, int y) {
    //     int x_parent = find(x);
    //     int y_parent = find(y);

    //     if(x_parent == y_parent) return;

    //     if(rank[x_parent] > rank[y_parent]) {
    //         //x_parent ko leader bana do
    //         parent[y_parent] = x_parent;
    //     } else if(rank[x_parent] < rank[y_parent]) {
    //         //y_parent ko leader bana do
    //         parent[x_parent] = y_parent;
    //     } else {
    //         //kisi ko bhi leader bana do and rank incremented by one
    //         parent[x_parent] = y_parent;
    //         rank[y_parent]++;
    //     }
    // }

    bool isSimilar(string str1, string str2) {

        if(str1 == str2) return true;

        int diff_cnt = 0;
        int n = str1.length();

        for(int i = 0; i < n; i++) {
            if(str1[i] != str2[i]) {
                diff_cnt++;
            }
        }

        return diff_cnt == 2;
    }

    // void dfs(int curr, unordered_map<int, vector<int>> &adj, vector<int> &vis) {
    //     vis[curr] = 1;

    //     for(auto &v : adj[curr]) {
    //         if(!vis[v]) {
    //             dfs(v, adj, vis);
    //         }
    //     }
    // } 

    void bfs(int curr, unordered_map<int, vector<int>> &adj, vector<int> &vis) {
        vis[curr] = 1;
        queue<int> q;
        q.push(curr);

        while(!q.empty()) {
            curr = q.front();
            q.pop();
            for(auto &v: adj[curr]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        // rank.resize(n, 0);
        // parent.resize(n);
        // for(int i = 0; i < n; i++) parent[i] = i;

        //dfs and bfs method
        unordered_map<int, vector<int>> adj;

        //int groupCount = n;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isSimilar(strs[i], strs[j])) {
                    // if(find(i) != find(j)) {
                    //     union_find(i, j);
                    //     groupCount--;
                    // }

                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }
            }
        }
        int groupCount = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                bfs(i, adj, vis);
                groupCount++;
            }
        }
        return groupCount;
        
        //Solve by all three method
        //bfs
        //dfs
        //union find

        //N = size of whole given strs array/vector
        //M = Size of each string

        //TC of BFS and DFS will be O(N^2 * M)
        //SC = O(N^2)

        //TC  of UNION Find will be O(N^2 * M)
        //SC = O(N)

    }
};