/*
Q_name:- Union-Find
Platform:- gfg
Description:- 
    This problem is to implement disjoint set union. There will be 2 incomplete functions namely union and find. You have to complete these functions. 

Union: Join two subsets into a single set.
isConnected: Determine which subset a particular element is in. This can be used for determining if two elements are in same subset.

Example 1:

Input:
N = 5
q = 4
Queries = 
Union(1,3)
isConnected(1,2)
Union(1,5)
isConnected(3,5)
Output:
0
1
Explanation: Initially all nodes 1 2 3 4 5
are not connected. 
After Union(1,3), node 1 and 3 will be
connected.
When we do isConnected(1,2),  as node 1
and 2 are not connected it will return 0.
After Union(1,5), node 1 and 5 will be
connected.
When we do isConnected(3,5),  as node
1 and 3 are connected, and node 1 and 5
are connected, hence 3 and 5 are
connected. Thus it will return 1.
Example 2:

Input:
N = 5
q = 4
Queries = 
Union(1,4)
Union(1,5)
isConnected(2,3)
Union(3,4)
Output: 0
Your Task:

You have to complete the function union_() which merges the node1 and node2. You will also have to complete the function isConnected() which will return whether the two nodes are connected.

Note: Both function will contain two arrays par[] and ranks1[] along with two nodes. Initially par[i] = i and rank1[i] = 1 

Expected Time Complexity: O(N + Q).
Expected Auxiliary Space: O(1).

Constraints: 
1 <= N <= 10^5
1<= Q <= 10^5
1 <= node1, node2 <= N
*/

class Solution
{
    public:
    
    int find(int i, int parent[]) {
        if(i == parent[i]) {
            return i;
        }
    
        return parent[i] = find(parent[i], parent);
    }
    
    //Function to merge two nodes a and b.
    void union_( int x, int y, int parent[], int rank[]) 
    {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
    
        if(x_parent == y_parent) return;
    
        if(rank[x_parent] > rank[y_parent]) {
            //x_parent ko leader bana do
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            //y_parent ko leader bana do
            parent[x_parent] = y_parent;
        } else {
            //kisi ko bhi leader bana do and rank incremented by one
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int parent[], int rank[])
    {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
    
        if(x_parent == y_parent) return true;
        
        return false;
    }
};