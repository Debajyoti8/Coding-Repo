class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Striver 
        //2nd method
        //Tabulaton code
        // Time-O(n×4)
        // Space-O(n×4) 
        int n=prices.size();

        //2d dp of (ind,buy,cap)
        vector<vector<int>> dp(n+1,vector<int>(5,0));

        //base case already covered (i==n t==4)

        //explore
        for(int i=n-1;i>=0;i--) //loop starts in opp. fashion
        {
            for(int t=3;t>=0;t--)  //loop starts in opp. fashion
            {
                //copy recurrence
                    if(t%2==0) //if not buy till  now,just buy it
                        dp[i][t]=max(-prices[i] + dp[i+1][t+1],dp[i+1][t]); //max(buy, skip)
                    else    //sell 
                        dp[i][t]=max(prices[i]+dp[i+1][t+1],dp[i+1][t]);
                
            }
        }

        //return will always be initial call made in recursion
        return dp[0][0];
    }
};