/*
Q_Name:- Task Scheduler
Given a character array tasks of size N, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
CPU has a cooldown period for each task. CPU can repeat a task only after atleast K units of time has passed after it did same task last time. It can perform other tasks in that time, can stay idle to wait for repeating that task.

Return the least number of units of times that the CPU will take to finish all the given tasks.

Example 1:

Input:
N = 6
K = 2
task[ ] = {'A', 'A', 'A', 'B', 'B', 'B'}
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is atleast 2 units of time between any two same tasks.
 
Example 2:

Input:
N = 12
K = 2
task[ ] = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}
Output: 16
Explanation:  
One possible solution is 
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function leastInterval() which takes the interger N, integer K and an character array tasks as parameters and returns the minimum unit of time required to complete all tasks.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 104
0 ≤ K ≤ 100
taski is upper-case English letter.
*/
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        // code here
        //for Approach : Watch this videos:- https://www.youtube.com/watch?v=tGw5GbDekTU

        // unordered_map<char, int> freq;
        // for(auto &t : tasks) {
        //     freq[t]++;
        // }
        
        // priority_queue<int> pq;
        
        // for(auto &f : freq) {
        //     pq.push(f.second);
        // }
        // int ans = 0;
        // while(!pq.empty()) {
        //     vector<int> temp;
        //     int tme = 0;
        //     for(int i = 0; i <= k; i++) {
        //         if(!pq.empty()) {
        //             temp.push_back(pq.top()-1);
        //             pq.pop();
        //             tme++;
        //         }
                
        //     }
        //     for(auto &t : temp) {
        //         if(t) pq.push(t);
        //     }
        //     ans += pq.empty() ? tme : k+1;
        // }
        
        // return ans;
        // //TC = O(N*K)
        // //SC = O(26)
        
        
        int res = 0,count = 0;
        
        vector<int>ct(26,0);
        
        for(char c:tasks)
        {   
            ct[c-'A']++;
            res = max(res,ct[c-'A']);
        }
        
        for(int x:ct)
        if(x == res)
        count++;
        
        return max(n,res + (res-1)*k + count - 1);
        
        
    }
};