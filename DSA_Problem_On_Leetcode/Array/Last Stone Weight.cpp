
/*
Q_Id:- 1046.
Q_Name:-  Last Stone Weight
Easy
Description:- 
    You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1
 

Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        /*
        Simple approach
        Why we thing that pq will be used
        since each time we have to required of max element and another just max element so 
        for this we have to used default max priority queue

        for each time we get two top element and according to given condition 
        check that which condition is full filled.

        TC = O(NlogN)
        SC = O(N)

        */
        int n = stones.size();

        if(n == 0) return 0;
        if(n == 1) return stones[0];

        priority_queue<int> pq;

        for(int i = 0; i < n; i++) {
            pq.push(stones[i]);
        }

        while(1) {
            if(pq.size() == 0 || pq.size() == 1) {
                break;
            }

            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(y != x) pq.push(y-x);
        }

        if(pq.size() == 0) return 0;
        return pq.top();
    }
};