/*
373. Find K Pairs with Smallest Sums
Medium
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
*/
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        int n1 = nums1.size();
        int n2 = nums2.size();
        
        priority_queue<pair<int, pair<int, int>>> pq; //(sum, (i, j)) // max heap priority queue

        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k) {
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else if(pq.size() >= k && pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }

        while(pq.size() > 0) {
            int first = pq.top().second.first;
            int second = pq.top().second.second;
            ans.push_back({first, second});
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

        //TC = (N1*N2*logK)
        //SC = O(K)

        
    }
};