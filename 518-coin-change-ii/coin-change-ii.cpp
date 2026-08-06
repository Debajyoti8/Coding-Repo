class Solution {
public:

    int f(int i,int amount, vector<int>& coins,vector<vector<int>> &dp)
    {
         if(amount==0) return 1;
         if(i==0)
         {
            if(amount%coins[i]==0)
            return 1;

            return 0;
         }
         if(dp[i][amount]!=-1) return dp[i][amount];

        int notpick=f(i-1,amount,coins,dp);
        int pick=0;
        if(coins[i]<=amount)
        pick=f(i,amount-coins[i],coins,dp);

        return dp[i][amount]=notpick + pick;
    }

    int change(int amount, vector<int>& coins) {
        //Memoization
        //tc-O(N*amt)
        //sc-O(N*amt)+ O(n)
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return f(n-1,amount,coins,dp);
    }
};