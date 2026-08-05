class Solution {
public:

    int f(int i,vector<int>& coins, int amount,vector<vector<int>> &dp)
    {
        
        if(i==0)
        {
            if(amount%coins[i]==0)
            return (amount/coins[i]);
            else 
            return 1e9;
        }
        if(dp[i][amount]!=-1)
        return dp[i][amount];


        int pick=1e9;
        if(coins[i]<=amount)
        pick=1+f(i,coins,amount-coins[i],dp);
        int notpick=f(i-1,coins,amount,dp);

        return dp[i][amount]=min(pick,notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        // Time Complexity: O(n × amount)
        // Space Complexity: O(n × amount) + O(amount)
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1, coins, amount,dp);


        if(ans >= 1e9)
            return -1;

        return ans;
    }
};