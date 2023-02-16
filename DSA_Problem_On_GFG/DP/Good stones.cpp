/*
Q_Name:- Good Stones
Platform:- GFG
Difficulty:- Medium
Description:- 
    Geek is in a geekland which have a river and some stones in it. 
    Initially geek can step on any stone. Each stone has a number 
    on it representing the value of exact step geek can move. 
    If the number is +ve then geeks can move right and if the number 
    is -ve then geeks can move left. Bad Stones are defined as the 
    stones in which if geeks steps, will reach a never ending loop 
    whereas good stones are the stones which are safe from never ending loops. 
    Return the number of good stones in river.

Constraints:- 
    1 <= n < 10^5 (where n is the length of the array)
    -1000 <= arr[i] < 1000
    Expected Time Complexity : O(N), N is the number of stones.
    Expected Auxiliary Space : O(N), N is the number of stones.
*/
class Solution{
    int mark(int curr, vector<int> &arr, vector<int> &visited) {
        //base cases
        int n = arr.size();
        
        if(curr >= n || curr < 0) {
            return 1;
        }
        
        if(visited[curr] != -1) {
            return visited[curr];
        }
        
        visited[curr] = 0;
        
        visited[curr] = mark(curr+arr[curr], arr, visited);
        
        return visited[curr];
        
        
    }
public:
    int goodStones(int n,vector<int> &arr){
        //int n = arr.size();
        vector<int> visited(n, -1);
        for(int i = 0; i < n; i++) {
            if(visited[i] != 0) {
                mark(i, arr, visited);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(visited[i] == 1) ans++;
        }
        return ans;
    }  
};