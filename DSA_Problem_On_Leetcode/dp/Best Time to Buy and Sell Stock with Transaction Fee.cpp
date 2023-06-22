/*
Q_Name:- 714. Best Time to Buy and Sell Stock with Transaction Fee
Difficulty:- Medium
Description:- 
    You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 10^4
1 <= prices[i] < 5 * 10^4
0 <= fee < 5 * 10^4
*/

class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& prices, int buy, int day, int fee) {
        if(day >= n) {
            return 0;
        }

        if(dp[day][buy] != -1) return dp[day][buy];

        int profit = INT_MIN;
        if(buy) {
            //means buy == true that means we don't have stock so we have to buy or not the stock
            int take = solve(prices, 0, day+1, fee) - prices[day];
            int not_take = solve(prices, 1, day+1, fee);
            profit = max({profit, take, not_take});
        } else {
            //means buy == false that means we already have stock so we need to sell or not this stock
            int sell = solve(prices, 1, day+1, fee) + prices[day]-fee; //if sell then they have to pay fees also
            int not_sell =  solve(prices, 0, day+1, fee);
            profit = max({profit, sell, not_sell});
        }

        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        //Recursive + memoization
        n = prices.size();
        // dp = vector<vector<int>> (50001, vector<int>(2, -1));
        // return solve(prices, 1, 0, fee); //solve(price_array, buy_or_not, day)

        //Iterative approach
        int buy = INT_MIN;
        int profit_after_sell = 0;

        for(int i = 0; i < n; i++) {
            buy = max(buy, profit_after_sell-prices[i]);
            profit_after_sell = max(profit_after_sell, buy+prices[i]-fee);
        }

        return profit_after_sell;

    }
};