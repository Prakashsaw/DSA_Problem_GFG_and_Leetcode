/*
Leetcode
1524. Number of Sub-arrays With Odd Sum
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long mod = 1e9+7;
        //Simple appraoch
        //using hash table to store frequencies with prefix sum % 2
        //find all subarray with even sum and then substract this to total subarray to 
        //find all subarray with odd sum
        //TC = O(N)
        //SC = O(N).
        int n = arr.size();
        unordered_map<int, long long int> mp;
        mp[0] = 1;
        long long int sum = 0;
        long long int ans = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(mp.count(sum%2)) {
                ans += mp[sum%2];
                //ans = ans % mod;
                mp[sum%2]++;
            } else {
                mp[sum%2] = 1;
            }
        }
        //ans = ans % mod;

        long long int total_sub_arrays = 1;
        total_sub_arrays *= n;
        total_sub_arrays *=  (n+1);
        total_sub_arrays /= 2 ;

        return (total_sub_arrays - ans)%mod;
    }
};