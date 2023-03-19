/*
Q_NAME:- Distinct Difference;
Platform:- gfg
Given an array A[] of length N. For each index i (1<=i<=N), 
find the diffference between the number of distinct element 
in it's left and right side in the array. 

*/
class Solution {
  public:
    vector<int> getDistinctDifference(int n, vector<int> &arr) {
        //simple approach
        //pre calculation
        //TC = O(N)
        //SC = O(N)
        
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int cnt = 0;
        unordered_map<int, bool> mp;
        for(int i = 0; i < n; i++) {
            left[i] = cnt;
            if(!mp.count(arr[i])) {
                mp[arr[i]] = true;
                cnt++;
            }
        }
        mp.clear();
        cnt = 0;
        for(int i = n-1; i >= 0; i--) {
            right[i] = cnt;
            if(!mp.count(arr[i])) {
                mp[arr[i]] = true;
                cnt++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(left[i]-right[i]);
        }
        return ans;
    }
};