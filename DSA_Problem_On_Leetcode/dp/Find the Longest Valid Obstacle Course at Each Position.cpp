/*
Q_Id:- 1964.
Q_Name:- Find the Longest Valid Obstacle Course at Each Position.
Q_Description:- 
    You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.

For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:

You choose any number of obstacles between 0 and i inclusive.
You must include the ith obstacle in the course.
You must put the chosen obstacles in the same order as they appear in obstacles.
Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.

 

Example 1:

Input: obstacles = [1,2,3,2]
Output: [1,2,3,3]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [1], [1] has length 1.
- i = 1: [1,2], [1,2] has length 2.
- i = 2: [1,2,3], [1,2,3] has length 3.
- i = 3: [1,2,3,2], [1,2,2] has length 3.
Example 2:

Input: obstacles = [2,2,1]
Output: [1,2,1]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [2], [2] has length 1.
- i = 1: [2,2], [2,2] has length 2.
- i = 2: [2,2,1], [1] has length 1.
Example 3:

Input: obstacles = [3,1,5,6,4,2]
Output: [1,1,2,3,2,2]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [3], [3] has length 1.
- i = 1: [3,1], [1] has length 1.
- i = 2: [3,1,5], [3,5] has length 2. [1,5] is also valid.
- i = 3: [3,1,5,6], [3,5,6] has length 3. [1,5,6] is also valid.
- i = 4: [3,1,5,6,4], [3,4] has length 2. [1,4] is also valid.
- i = 5: [3,1,5,6,4,2], [1,2] has length 2.
 

Constraints:

n == obstacles.length
1 <= n <= 10^5
1 <= obstacles[i] <= 10^7

*/
/*
For details explanation and short revision watch:- https://www.youtube.com/watch?v=sUtUgMW2kMY
*/

class Solution {
    void LIS(int n, vector<int> &arr, vector<int> &lis) {
        //int lis[n] = {0};
        lis[0] = 1;
        for(int i = 1; i < n; i++) {
            lis[i] = 1;
            for(int j = 0; j < i; j++) {
                if(arr[i] >= arr[j] && lis[i] < lis[j]+1) {
                    lis[i] = lis[j]+1;
                }
            }
        }
        // int maxi = INT_MIN;
        // for(int i = 0; i < n; i++) {
        //     maxi = max(maxi, lis[i]);
        // }
        // return maxi;
    }

    void solveOptimal(int n, vector<int> &arr, vector<int> &lis) {
        if(n == 0) return ;
        vector<int> v;
        v.push_back(arr[0]);
        lis[0] = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] >= v.back()) {
                v.push_back(arr[i]);
                lis[i] = v.size();
            } else {
                int findIndex = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
                v[findIndex] = arr[i];
                lis[i] = findIndex+1;
            }
        }
        //return v.size();
    }
    
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        //brute force
        //Simple LIS Approach
        //TC = O(N*N)
        //SC = O(1) If exclude ans vector
        //Status:- TLE 
        int n = obstacles.size();
        vector<int> ans(n);
        //LIS(n, obstacles, ans);
        solveOptimal(n, obstacles, ans);
        //TC = O(NlogN)
        //SC = O(N)
        return ans;

    }
};