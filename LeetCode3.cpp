#include <iostream>
#include <vector>
using namespace std;
// Leetcode Extra For buying and selling stock



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // minimum price seen so far
        int maxProfitValue = 0;   // max profit

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];       // update min price
            }
            else if(prices[i] - minPrice > maxProfitValue) {
                maxProfitValue = prices[i] - minPrice;  // update max profit
            }
        }

        return maxProfitValue;
    }
};