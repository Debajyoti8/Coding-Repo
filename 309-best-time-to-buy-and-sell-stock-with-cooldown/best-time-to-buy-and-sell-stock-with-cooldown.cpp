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
            for(int buy=0;buy<2;buy++)
            {
                //copy recursion
                int profit=0;
                if(buy) //if not buy till  now,just buy it
                profit=max(-prices[i] + dp[i+1][0] ,dp[i+1][1]); //max(buy, skip)
                else    //if sell cooldown occurs /skip
                profit=max(prices[i] + dp[i+2][1] , dp[i+1][0]);

                dp[i][buy]=profit;
            }
        }

        return dp[0][1];
    }
};