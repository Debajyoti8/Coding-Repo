class Solution {
public:

    int f(int i,int n,vector<int>& prices,int buy,int fee,vector<vector<int>> &dp)
    {
        //base case
        if(i==n) //Agar saare days khatam ho gaye:toh ab profit kama hi nahi sakte.
        return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy) //if not buy till  now,just buy it
        profit=max(-prices[i] + f(i+1,n,prices,0,fee,dp),f(i+1,n,prices,1,fee,dp)); //max(buy, skip)
        else    //sell
        profit=max(prices[i]-fee + f(i+1,n,prices,1,fee,dp), f(i+1,n,prices,0,fee,dp));

        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        //Memoization code
        //Time - O(n) 
        //Space- O(n) + O(n) = O(n)
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,n,prices,1,fee,dp);
    }
};