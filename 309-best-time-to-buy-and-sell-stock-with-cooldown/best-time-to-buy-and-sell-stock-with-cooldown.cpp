class Solution {
public:
    int f(int i,int n,vector<int>& prices,int buy,vector<vector<int>> &dp)
    {
        //base case
        if(i>=n) //Agar saare days khatam ho gaye:toh ab profit kama hi nahi sakte.
        return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy) //if not buy till  now,just buy it
        profit=max(-prices[i] + f(i+1,n,prices,0,dp),f(i+1,n,prices,1,dp)); //max(buy, skip)
        else    //if sell cooldown occurs /skip
        profit=max(prices[i] + f(i+2,n,prices,1,dp), f(i+1,n,prices,0,dp));

        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        //Memoiztaion
        // Time: n × 2 = O(n)
        // Space: O(2n) = O(n)+O(n)  [f(0) → f(1) → ... → f(n)] Rec stack
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,n,prices,1,dp);
    }
};