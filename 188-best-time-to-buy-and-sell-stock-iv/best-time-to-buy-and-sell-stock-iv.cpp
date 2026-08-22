class Solution {
public:
    int f(int i,int t,vector<int>& prices,int k,int n,vector<vector<int>> &dp)
    {
        if(i==n||t==2*k) return 0;
        if(dp[i][t]!=-1) return dp[i][t];

        if(t%2==0)  //buy/skip
            return dp[i][t]=max(-prices[i]+f(i+1,t+1,prices,k,n,dp) , f(i+1,t,prices,k,n,dp));
        else //sell/skip
            return dp[i][t]=max(prices[i]+f(i+1,t+1,prices,k,n,dp) , f(i+1,t,prices,k,n,dp));    
    }

    int maxProfit(int k, vector<int>& prices) {
        //Striver 
        //2nd method
        //Memoization code
        // Time-O(n×k)
        // Space-O(nk) + O(n) = O(nk)
        int n=prices.size();

        //2d dp of (ind,trans)
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));   
        
        return f(0,0,prices,k,n,dp);
    }
};