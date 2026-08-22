class Solution {
public:

    int f(int i,int n,vector<int>& prices,int buy,int cap,vector<vector<vector<int>>> &dp)
    {
        //base case
        if(i==n || cap==0) //Agar saare days khatam ho gaye:toh ab profit kama hi nahi sakte.
        return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit=0;
        if(buy) //if not buy till  now,just buy it
        profit=max(-prices[i] + f(i+1,n,prices,0,cap,dp),f(i+1,n,prices,1,cap,dp)); //max(buy, skip)
        else    //sell 
        profit=max(prices[i] + f(i+1,n,prices,1,cap-1,dp), f(i+1,n,prices,0,cap,dp));
        //jab buy+sell hoga tabhi 1 transac complete hoga so cap dec hoga

        return dp[i][buy][cap]=profit;
    }

    int maxProfit(vector<int>& prices) {
        //Striver 
        //Memoization code
        // Time-O(n × 2 × 3)
        // Space-O(n × 2 × 3)+O(n)
        int n=prices.size();
        
        //3d dp of (ind,buy,cap)
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return f(0,n,prices,1,2,dp);
    }
};