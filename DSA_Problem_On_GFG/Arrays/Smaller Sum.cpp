/*
Q_Name:- Smaller Sum
Platform:- gfg
POTD:- 22=04-2023.
Q_Difficulty:- medium
Description:- 
    You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].

Example 1:

Input:
n = 3
arr = {1, 2, 3}
Output:
0 1 3
Explanation:
For 1, there are no elements lesser than itself.
For 2, only 1 is lesser than 2.
And for 3, 1 and 2 are lesser than 3, so the sum is 3.
Example 2:

Input:
n = 2
arr = {4, 4}
Output:
0 0
Explanation:
For 4, there are no elements lesser than itself. 
For 4, there are no elements lesser than itself.
There are no smaller elements than 4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallerSum() which takes an integer n and an array arr and returns an array of length n , the answer for every index.

Expected Time Complexity:O(n log n)
Expected Space Complexity:O(n)

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= 10^9

*/
class Solution{
public:
    vector<long long> smallerSum(int n, vector<int> &arr){
        // //brute force
        // vector<long long> ans(n, 0);
        // for(int i = 0; i < n; i++) {
        //     long long sum = 0;
        //     for(int j = 0; j < n; j++) {
        //         if(i != j and arr[j] < arr[i]) {
        //             sum += arr[j];
        //         }
        //     }
        //     ans[i] = sum;
        // }
        // return ans;
        
        // //TC = O(N*N)
        // //SC = O(1)
        
        
        //Let's thing optimize approach
        // //map method
        // vector<int> num(arr.begin(), arr.end());
        
        // long long int sum = 0;
        // for(int i = 0; i < n; i++) {
        //     sum += arr[i];
        // }
        
        // sort(arr.begin(), arr.end(), greater<int>());
        // unordered_map<int, long long int> mp; //arr[i] vs req_sum
        
        // for(int i = 0; i < n; i++) {
        //     sum -= arr[i];
        //     mp[arr[i]] = sum;
        // }
        
        // vector<long long> ans(n, 0);
        // for(int i = 0; i < n; i++) {
        //     ans[i] = mp[num[i]];
        // }
        // return ans;
        
        // //TC + O(NlogN)
        // //SC + O(2N) = O(N)
        
        
        //Binary search approach
        vector<int> num(arr.begin(), arr.end());
        
        sort(arr.begin(), arr.end());
        
        vector<long long int> sum(n, 0);
        
        int cnt = 1;
        
        for(int i = 1; i < n; i++) {
            if(arr[i-1] == arr[i]) {
                cnt++;
                sum[i] = sum[i-1];
            } else {
                sum[i] = sum[i-1] + arr[i-1]*cnt;
                cnt = 1;
            }
        }
        
        vector<long long > ans(n);
        for(int i = 0; i < n; i++) {
            int indx = lower_bound(arr.begin(), arr.end(), num[i]) - arr.begin();
            ans[i] = sum[indx];
        }
        
        return ans;
        
        //TC = O(NlogN) + O(NlogN) = O(NlogN)
        //SC = O(2N) = O(N) 
        
        
    }
};