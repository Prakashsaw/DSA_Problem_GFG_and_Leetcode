/*
Q_Id:- 2563.
Q_Name:- Count the Number of Fair Pairs;
Platform:- Leetcode.
Quetion Description:-
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper

Constraints:- 
1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109
*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // //brute force
        //TC = O(N*N)
        //SC = O(1)

        // int n = nums.size();
        // long long ans = 0;
        // unordered_map<int, int> mp;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         long long sum = nums[i]+nums[j];
        //         if(sum >= lower && sum <= upper) ans++;
        //     }
        // }
        // return ans;



        //Optimize approach
        //TC = O(NlogN)
        //SC = O(1)

        int n = nums.size();
        // Sort the given array
        sort(nums.begin(), nums.end());
    
        int right = n - 1;
        long long ans = 0;
    
        // Iterate until right > 0
        while (right > 0) {
    
            // Starting index of element
            // whose sum with nums[right] >= lower
            auto it1 = lower_bound(nums.begin(), nums.end(), lower - nums[right]);
    
            int start = it1 - nums.begin();
    
            // Ending index of element
            // whose sum with nums[right] <= upper
            auto it2 = upper_bound(nums.begin(), nums.end(), upper - nums[right]);
    
            --it2;
    
            int end = it2 - nums.begin();
    
            // Update the value of end
            end = min(end, right - 1);
    
            // Add the count of elements
            // to the variable count
            if (end - start >= 0) {
                ans += (end - start + 1);
            }
    
            right--;
        }
    
        // Return the value of count
        return ans;
    }
};