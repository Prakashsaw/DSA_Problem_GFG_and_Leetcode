/*
Q_name:- Cake Distribution Problem
platform:- gfg
Difficulty:- Medium
Q_Description:- 

    Geek is organizing a birthday party, so his friends brought a cake for him. The cake consists of N chunks, whose individual sweetness is represented by the sweetness array. Now at the time of distribution, Geek cuts the cake into K + 1 pieces to distribute among his K friends. One piece he took for himself. Each piece consists of some consecutive chunks. He is very kind, so he left the piece with minimum sweetness for him.

You need to find the maximum sweetness that the Geek can get if he distributes the cake optimally.

Example 1:

Input:
N  = 6, K = 2
sweetness[] = {6, 3, 2, 8, 7, 5}
Output:
9
Explanation:
Geek can divide the cake to [6, 3], [2, 8], [7, 5] 
with sweetness level 9, 10 and 12 respectively.
Example 2:

Input:
N  = 7, K = 3
sweetness[] = {1, 2, 4, 7, 3, 6, 9}
Output:
7
Explanation:
Geek can divide the cake to [1, 2, 4], [7], [3, 6], [9] 
with sweetness level 7, 7, 9 and 9 respectively.
Your Task:
You need to complete the maxSweetness() function which takes an integer array of sweetness, an integer N and an integer K as the input parameters and returns an integer denoting the maximum sweetness that the Geek can get.

Expected Time Complexity: O(NlogM), where M is the sum of elements in the array.
Expected Space Complexity: O(1)

Constraints:
1 <= N <= 105
0 <= K < N
1 <= sweetness[i] <= 10^9
*/
class Solution{
    public:
    bool isDistributed(vector<int>& sweetness, int n, int mid, int k) {
        
        int cnt = k;
        
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += sweetness[i];
            
            if(sum >= mid) {
                cnt--;
                sum = 0;
            }
        }
        
        if(cnt <= 0) {
            return true;
        }
        return false;
    }
    int maxSweetness(vector<int>& sweetness, int n, int k) {
        //same as page allocation method
        // advance binary search algorithm
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += sweetness[i];
        }
        
        int start = 0;
        int end = sum;
        
        int mid;
        int ans = INT_MIN;
        while(start <= end) {
            mid = start + (end-start)/2;
            if(isDistributed(sweetness, n, mid, k+1)) {
                ans = max(ans, mid);
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        
        return ans;
        
        //TC = O(N*log(sum of all arr))
        // SC = O(1)
    }
};