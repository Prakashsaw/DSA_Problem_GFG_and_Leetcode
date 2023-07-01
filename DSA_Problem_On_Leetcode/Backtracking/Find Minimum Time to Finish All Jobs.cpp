/*
1723. Find Minimum Time to Finish All Jobs
Level:- Hard
Companies:- Google
Description:- 
    You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

Return the minimum possible maximum working time of any assignment.

 

Example 1:

Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.
Example 2:

Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.
 

Constraints:

1 <= k <= jobs.length <= 12
1 <= jobs[i] <= 10^7
*/

class Solution {
public:
    void solve(int indx, vector<int>& jobs, vector<int>& workers, int k, int &ans) {
        //base case
        if(indx == jobs.size()) {
            int mx = *max_element(workers.begin(), workers.end());
            ans = min(ans, mx);
            return ;
        }

        //if max element greater than ans then no further min element are possible
        if(*max_element(workers.begin(), workers.end()) >= ans) {
            return;
        }


        for(int i = 0; i < k; i++) {
            //if previous element is smaller than current in workrs then prune the function call
            if(i > 0 && workers[i] >= workers[i-1]) {
                continue;
            }

            workers[i] += jobs[indx];
            solve(indx+1, jobs, workers, k, ans);
            workers[i] -= jobs[indx]; //Backtrack or revert back
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        //base case
        sort(jobs.begin(), jobs.end(), greater<int>());
        if(jobs.size() == k) {
            return jobs[0];
        }
        
        vector<int> workers(k, 0);
        int ans = INT_MAX;
        solve(0, jobs, workers, k, ans);
        return ans;
    }

    //TC = Less than O(K^N) where k = number of workers and n = number of jobs
    //SC= O(K + N)
};