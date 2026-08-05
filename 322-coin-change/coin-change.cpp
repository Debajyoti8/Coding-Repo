class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        // Time Complexity: O(n × amount)
        // Space Complexity: O(n × amount)
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        //base cases for index 0
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)
            dp[0][t]=t/coins[0];
            else 
            dp[0][t]=1e9;
        }

        //change parameters
        for(int i=1;i<n;i++)
        {
           for(int t=0;t<=amount;t++)
           {
                //copy recursion code
                int pick=1e9;
                if(coins[i]<=t)
                pick=1+ dp[i][t-coins[i]];
                int notpick=dp[i-1][t];

                dp[i][t]=min(pick,notpick);
           }
        }

        int ans = dp[n-1][amount];


        if(ans >= 1e9)
            return -1;

        return ans;
    }
};