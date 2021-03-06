/*
    题目：
        给定不同面额的硬币 coins 和一个总金额 amount。
        编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
        如果没有任何一种硬币组合能组成总金额，返回 -1。
        你可以认为每种硬币的数量是无限的。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount+1;
        std::vector<int> dp(amount+1, Max);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(int j = 0; j < coins.size(); ++j){
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};