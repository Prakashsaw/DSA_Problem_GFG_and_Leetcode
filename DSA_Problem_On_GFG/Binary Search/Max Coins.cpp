/*
Que:- Max Coins
Description:- 
    You are given a 2D integer array ranges whose length is n where ranges[i]=[starti, end,coinsi] means all integers from starti to endi inclusive starti and endi are present and we get coinsi amount of coins when we select this ith range. You can select at most two intervals so as to collect maximum coins but if you select two ranges then those two ranges should not intersect or overlap but can touch each other.

Note: You can select at max 2 ranges and they should not intersect with each other but they can touch themselves.

Example 1:

Input :
n=3
ranges={{1,3,4},{2,3,5},{3,4,2}}
Output: 7
Explanation:
We can see that we can take 2nd and 
3rd ranges as they are not intersecting
(only touching) we get maximum Coins by 
taking these ranges(5+2=7).
Example 2:

Input :
n=5
ranges={{1,3,4},{2,3,5},{3,4,2},{5,8,9},{2,8,10}}
Output: 14
Explanation:
We can see that we can take 2nd and 
4th ranges as they are not intersecting 
we get maximum Coins(5+9=14) by taking 
these ranges.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes an integer n(length of ranges), integer 2D integer array ranges, and you have to return the maximum number of coins you got after selecting at most two ranges that are not intersecting.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(n)

Constraints:
1<=n<=105
0<=ranges[i][0]<=ranges[i][1]<=10^9
0<=ranges[i][2](coins)<=10^6
The sum of n over all test cases won't exceed 10^6
*/
class Solution{
public:
    
    int solve(vector<pair<int, int>> &vec, int end_time) {
        int st = 0;
        int end = vec.size()-1;
        int indx = -1;
        while(st <= end) {
            int mid = st + (end-st)/2;
            
            if(vec[mid].first <= end_time) {
                indx = mid;
                st = mid+1;
            } else {
                end = mid-1;
            }
        }
        if(indx == -1) return 0;
        
        return vec[indx].second;
    }

    static bool comp(vector<int> &v1, vector<int> &v2) {
        if(v1[1] == v2[1]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }
    int maxCoins(int n,vector<vector<int>> &ranges){
        //brute force
        //status TLE
        if(n == 0) return 0;
        if(n == 1) return ranges[0][2];
        sort(ranges.begin(), ranges.end(), comp);
        int ans = INT_MIN;
        vector<pair<int, int>> vec; //for storing <end_time, coins> best this till left of ith in ranges
        
        for(int i = 0; i < n; i++) {
            // for(int j = i+1; j < n; j++) {
            //     if(ranges[i][1] <= ranges[j][0]) {
            //         ans = max(ans, ranges[i][2]+ranges[j][2]);
            //     }
            // }
            
            ans = max(ans, solve(vec, ranges[i][0]) + ranges[i][2]);
            
            if(vec.empty() || vec.back().second < ranges[i][2]) {
                vec.push_back({ranges[i][1], ranges[i][2]});
            }
            
        }
        // for(int i = 0; i < n; i++) {
        //     ans = max(ans, ranges[i][2]);
        // }
        return ans;
        
        //optimize using binary seach 
        //TC = O(NlogN)
        //SC = O(N)
        
    }
};