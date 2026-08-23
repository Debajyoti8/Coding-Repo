class Solution {
public:

    int maxProfit(vector<int>& prices) {
        //Tabulation
        // Time: n × 2 = O(n)
        // Space: O(2n) = O(n)
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        //base case already covererd

        for(int i=n-1;i>=0;i--)
        {
            //more optimised tabulation remove buy
                //copy recursion                
                dp[i][1]=max(-prices[i] + dp[i+1][0] ,dp[i+1][1]); //max(buy, skip)
                //if sell cooldown occurs /skip
                dp[i][0]=max(prices[i] + dp[i+2][1] , dp[i+1][0]);                
            
        }

        return dp[0][1];
    }
};