/*Q_name:- 309. Best Time to Buy and Sell Stock with Cooldown
Difficulty:- Medium
Description:- 
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(vector<int>& prices, int buy, int day) {
        if(day >= n) {
            return 0;
        }

        if(dp[day][buy] != -1) return dp[day][buy];

        int profit = INT_MIN;
        if(buy) {
            //means buy == true that means we don't have stock so we have to buy or not the stock
            int take = solve(prices, 0, day+1) - prices[day];
            int not_take = solve(prices, 1, day+1);
            profit = max({profit, take, not_take});
        } else {
            //means buy == false that means we already have stock so we need to sell or not this stock
            int sell = solve(prices, 1, day+2) + prices[day]; //day+2 because just after sell one day is cooldown day;
            int not_sell =  solve(prices, 0, day+1);
            profit = max({profit, sell, not_sell});
        }

        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
    //    int n = prices.size();
    //     if(n < 2) return 0;
    //     vector<int>buy(n), sell(n), rest(n);
    //     buy[0] = -prices[0];
    //     sell[0] = 0;
    //     rest[0] = 0;
    //     for(int i = 1; i < n; i++){
    //         buy[i] = max(buy[i - 1], rest[i - 1] - prices[i]);
    //         sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    //         rest[i] = max(rest[i - 1], sell[i - 1]);
    //     }
    //     return max(rest[n - 1], sell[n - 1]); 

            //Recursive + memoization
            n = prices.size();
            dp = vector<vector<int>> (5001, vector<int>(2, -1));
            return solve(prices, 1, 0); //solve(price_array, buy_or_not, day)
    }
};