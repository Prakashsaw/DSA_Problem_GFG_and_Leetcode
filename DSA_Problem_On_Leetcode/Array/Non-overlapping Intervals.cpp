/*
Question Id:- 435. 
QueName:- Non-overlapping Intervals
Companies:- Google, Facebook, amazon, microsoft
Description:- 
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& interval) {
        
        int n = interval.size();
        if(n <= 1) return 0;
        sort(interval.begin(), interval.end());
        int ans = 0;
        int i = 0, j = 1;
        while(j < n) {
            int cs = interval[i][1];
            int ce = interval[i][1];
            int ns = interval[j][0];
            int ne = interval[j][1];

            if(ce > ns) {
                if(ce <= ne) {
                    j++;
                } else {
                    i = j;
                    j++;
                }
                ans++;
            } else {
                i = j;
                j++;
            }
        }
        return ans;
        //TC = O(N)
        //SC = O(1)
    }
};